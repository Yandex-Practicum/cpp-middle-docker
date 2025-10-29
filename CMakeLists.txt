cmake_minimum_required(VERSION 3.30)
project(app VERSION 1.0.0 LANGUAGES CXX)

#
# set(CMAKE_CXX_STANDARD 26) - На данный момент Boost не поддерживает версию стандарта 26
#
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    # Не больше одной ошибки за раз
    add_compile_options(-fmax-errors=1)
endif()

# Ищем необходимые библиотеки
find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)
find_package(absl REQUIRED)
find_package(Boost REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(SQLite3  REQUIRED)
find_package(range-v3 REQUIRED)

# Библиотека nvidia/stdexec распространяется с использованием CPM
include(FetchContent)
FetchContent_Declare(
  CPM
  GIT_REPOSITORY https://github.com/cpm-cmake/CPM.cmake
  GIT_TAG origin/master
)
FetchContent_MakeAvailable(CPM)

CPMAddPackage(
    NAME stdexec
    GITHUB_REPOSITORY NVIDIA/stdexec
    GIT_TAG main
    OPTIONS
        "STDEXEC_BUILD_EXAMPLES OFF"
        "STDEXEC_BUILD_TESTS OFF"
)

#
# Создаём библиотеку, в которую добавляются все используемые внутренние и внешние зависимости.
# Такой подход удобен тем, что позволяет собрать все нужные зависимости в одном месте и затем подключать эту библиотеку как к основному приложению, так и к тестам.
#
set (target_impl ${PROJECT_NAME}_impl)
add_library(${target_impl} INTERFACE)

# Линкуем к ней сторонние библиотеки
target_link_libraries(${target_impl}
    INTERFACE
        STDEXEC::stdexec
        abseil::abseil
        boost::boost
        openssl::openssl
        SQLite::SQLite3
        range-v3::range-v3)


# Указываем пути до include папок сторонних библиотек
# BUILD_INTERFACE автоматически подключает include-пути всех библиотек, указанных в target_link_libraries
target_include_directories(${target_impl}
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

# Добавляем сборку CMakeLists.txt из папки src
add_subdirectory(src)
