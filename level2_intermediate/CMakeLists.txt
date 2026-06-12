# Crea l'eseguibile del test
add_executable(level2_tests shopping_cart.cpp test_cart.cpp)

# Collega Google Test
target_link_libraries(level2_tests gtest_main)

# Rende i test visibili a CTest
include(GoogleTest)
gtest_discover_tests(level2_tests)