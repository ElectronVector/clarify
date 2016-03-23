# behav

A Given-When-Then style unit testing framework for C.

Simply include behav.h to use it.

See test_behav.c for an example.

Limitations
- You can only have a single Scenario per test file.
- You can only have a single When nested in a Given.
- You can only have a single Then nested in a When.

Each test stops after the first ASSERT fails. Other tests continue to run.

Run the sample tests with: `rake`
