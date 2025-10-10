#
# Создаём исполняемый таргет на основе одного main.cpp файла и подключаем к нему нашу библиотеку
#
set (target ${PROJECT_NAME})
add_executable(${target} "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

# Линкуем к ней нашу библиотеку
target_link_libraries(${target} PRIVATE ${target_impl})


# ================================================================================================================================= #


#
# Создаём исполняемый таргет для Unit тестирования и подключаем к нему нашу библиотеку
#
add_executable(unit_tests "${CMAKE_CURRENT_SOURCE_DIR}/unit_tests.cpp")

target_link_libraries(unit_tests
    PRIVATE
        ${target_impl}
        gtest::gtest)

target_include_directories(unit_tests
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)


# ================================================================================================================================= #


#
# Создаём исполняемый таргет для Benchmark тестирования и подключаем к нему нашу библиотеку
#
add_executable(benchmark_tests "${CMAKE_CURRENT_SOURCE_DIR}/benchmark_tests.cpp")

target_link_libraries(benchmark_tests
    PRIVATE
        ${target_impl}
        #
        # Библиотека benchmark использует собственный main, поэтому для её использования потребуется удалить функцию main()
        #
        benchmark::benchmark)

target_include_directories(benchmark_tests
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
