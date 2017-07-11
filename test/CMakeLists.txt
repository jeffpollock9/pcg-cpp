
set(RANDO_TESTS
    first_1k_equal)

foreach (test ${RANDO_TESTS})
    set(TEST_NAME "${test}_test")
    add_executable(${TEST_NAME} ${test}.cpp)
    target_link_libraries(${TEST_NAME} rando pcg-cpp gtest_main)
    add_test(${test} ${TEST_NAME})
endforeach ()
