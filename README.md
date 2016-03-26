# Clarify

Clarify is BDD-style unit test framework for C. It allows you to write Given-When-Then style unit tests by including a single header file.

## How to use it

Just copy the [clarify.h](https://raw.githubusercontent.com/ElectronVector/clarify/master/clarify.h) header file somewhere into your project, and then create test files like this:

```c
SCENARIO()
{
    GIVEN("Some initial state")
    {
        WHEN("something happens")
        {
            THEN("the expected result occurs")
            {
                ASSERT(expected == actual);
            }
        }
        WHEN("something else happens")
        {
            THEN("the another expected result occurs")
            {
                ASSERT(expected == actual);
            }
        }
    }
    
    GIVEN("Some other initial state")
    {
        WHEN("something happens")
        {
            THEN("the expected result occurs")
            {
                ASSERT(expected == actual);
            }
        }
    }
}
```

See the examples folder for an example.

Limitations
- You can only have a single Scenario per test file.
- You must have at least one given, when and then.

Each test stops after the first ASSERT fails. Other tests continue to run.

Run the sample tests with: `rake`

Warning: Watch out for stray semicolons at then end of your statements. For example:
```c
    WHEN("something happens"); // <-- This semicolon will break your tests.
```
This will break your tests in non-obvious ways. Recommend compiling with -W -Wall flags to warn on these errors.