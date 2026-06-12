# Crea l'eseguibile del test unendo il codice del prof e quello dello studente
add_executable(level1_tests config_parser.cpp test_parser.cpp)

# Collega la libreria di Google Test (include il main() di default)
target_link_libraries(level1_tests gtest_main)

# Rende i test visibili a CTest/GitHub Actions
include(GoogleTest)
gtest_discover_tests(level1_tests)