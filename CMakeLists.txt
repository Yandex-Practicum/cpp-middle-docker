cmake_minimum_required(VERSION 3.31.6)
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
find_package(benchmark REQUIRED)
find_package(absl REQUIRED)
find_package(Boost REQUIRED)
# find_package(OpenSSL REQUIRED)
#find_package(SQLite3  REQUIRED)


# Создаём исполняемый таргет с одним cpp файлом
add_executable(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/main.cpp")


# Указываем пути до include папок сторонних библиотек
target_include_directories(${PROJECT_NAME} PUBLIC
    ${benchmark_INCLUDE_DIRS}
    ${absl_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
    # ${OPENSSL_INCLUDE_DIR}
    # ${SQLite3_INCLUDE_DIR}
)

# Линкуем к нему сторонние библиотеки
target_link_libraries(${PROJECT_NAME} PRIVATE 
    benchmark::benchmark_main
    abseil::abseil
    boost::boost
    # openssl::openssl
    # SQLite::SQLite3
)
