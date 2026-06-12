# Crea l'eseguibile del test
add_executable(level3_tests mock_database.cpp test_database.cpp)

# Collega Google Test
target_link_libraries(level3_tests gtest_main)

# Rende i test visibili a CTest
include(GoogleTest)
gtest_discover_tests(level3_tests)