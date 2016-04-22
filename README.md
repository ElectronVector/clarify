# Clarify

Clarify is a BDD-style unit test framework for C. It allows you to write Given-When-Then style unit tests by including a single header file.

## Features

- BDD test names in plain text (no more gigantic test function names!).
- It's just C.
- Small and lightweight.
- No test-running boiler plate required.
- No long jump required.

## How to use it

Just copy the [clarify.h](https://raw.githubusercontent.com/ElectronVector/clarify/master/clarify.h) header file somewhere into your project, and then create test files like this:

```c
#include "clarify.h"

RUN_TESTS()
{
    GIVEN("Some initial state")
    {
        WHEN("something happens")
        {
            THEN("the expected result occurs")
            {
                REQUIRE(expected == actual);
            }
        }
        WHEN("something else happens")
        {
            THEN("the another expected result occurs")
            {
                REQUIRE(expected == actual);
            }
        }
    }

    GIVEN("Some other initial state")
    {
        WHEN("something happens")
        {
            THEN("the expected result occurs")
            {
                REQUIRE(expected == actual);
            }
        }
    }
}
```

The `RUN_TESTS()` macro provides a `main()` for your application, so you can run your test file by compiling it with **GCC**. No test runners or boiler plate required!

```
gcc -W -Wall my_test_file.c file_under_test.c -o my_test
```

Then execute your tests by running the binary:

```
./my_test
```

## Nesting tests (and changing state)

For each WHEN or THEN clause, the parent GIVEN and/or WHEN clauses are re-run, so that the initial state is reset before each test is run. This means that no "setup" or "teardown" functions are necessary -- which are common in other types of test frameworks.


## Failures

When a test fails, you get a message telling you exactly where the problem is:

```
test_power_button.c: Running Tests...
---------------------------------------------------
Test at test_power_button.c:6 FAILED
---------------------------------------------------
  Given: the power is off
   When: the power button is momentarily pressed
   Then: the power turns on
---------------------------------------------------
FAILED at test_power_button.c:20:
  REQUIRE( power_button_getPowerState() == POWER_OFF )
```

## Example

There is an example in [examples/power_button](https://github.com/ElectronVector/clarify/tree/master/examples/power_button). You can use `rake` to run the tests (requires installation of Ruby and Rake).

## Limitations

- The Clarify macros use nested functions, and so require GCC for compilation.
- You can only have a single `RUN_TESTS()` macro per test file.
- To define a test, you must have at least one `GIVEN()`, `WHEN()`, and `THEN()` clause.
- Each `THEN()` stops after the first REQUIRE fails. Other tests continue to run.

Warning: Watch out for stray semicolons at then end of your statements. For example:
```c
    WHEN("something happens"); // <-- This semicolon will break your tests.
```
This will break your tests in non-obvious ways. I recommend compiling with -W -Wall flags to warn on these errors.

Don't put any code in the places indicated below. It won't be run.

```c
#include "clarify.h"

RUN_TESTS()
{
    GIVEN("Some initial state")
    {
        WHEN("something happens")
        {
            THEN("the expected result occurs")
            {
                REQUIRE(expected == actual);
            }
            // ** Don't put code here.
        }
        // ** Don't put code here.
    }
}
```

## To Do

- Print values on error.
