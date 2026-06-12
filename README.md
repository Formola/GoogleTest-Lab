# Testing Laboratory

Welcome to the Cefriel introductory laboratory on **Testing**. In this repository, you will find three exercises of increasing difficulty designed to help you learn how to test professional code.

## Prerequisites

In order to proceed locally ensure you have the following installed:

* **CMake** (version 3.14 or higher)
* A C++ compiler (GCC, Clang, or MSVC)
* **Git**

## Repository Structure

The project is divided into three levels, each contained in its own directory:

1. `level1_basic/`: Testing pure functions and basic input validation.
2. `level2_intermediate/`: Testing classes with internal state and resource management.
3. `level3_advanced/`: Using **Test Fixtures** (`TEST_F`) to manage complex test environments.

## Workflow

Your goal is to complete the missing test cases until the GitHub Actions pipeline turns "green".

1. **Fork** this repository to your own GitHub account.
2. **Clone** your fork to your local machine:

   ```bash
   git clone <your-fork-url>
   cd cefriel2026
   ```

3. **Build the project**:

   ```bash
   cmake -B build
   cmake --build build
   ```

4. **Implement the tests**: Open the `test_*.cpp` files in each folder. You will find `// TODO:` comments indicating where you need to write your test code. Follow the instructions to cover the required scenarios.
5. **Verify locally**: You can run all tests from your terminal inside the `build/` directory using:

   ```bash
   ctest --output-on-failure
   ```

6. **Push your changes**: Once all tests pass locally, `git push` your changes to your fork. GitHub Actions will automatically run the tests on the server. If your code is correct, the build status will become **Passing (green)**.

## Guidelines for Level 3

For Level 3, you must define the `DatabaseTest` class yourself by inheriting from `testing::Test`. Make sure to:

* Use the `protected:` access modifier so your test cases can access the database object.
* Implement `SetUp()` and `TearDown()` to initialize and clean up your database before and after each test.
* Ensure you define the `DatabaseTest` class **before** using any `TEST_F(DatabaseTest, ...)` macros.

## References

* [GoogleTest Primer Documentation](https://google.github.io/googletest/primer.html)
* Refer to the provided course slides for the correct syntax of assertions (`EXPECT_EQ`, `ASSERT_NE`, etc.).
