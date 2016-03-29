/*
 Clarify is a BDD-style unit testing framework for C.
*/

#include <stdio.h>
#include <stdbool.h>

#define REQUIRE(boolean_test) \
    do { \
        if (!(boolean_test)) { \
            test_count_failed++; \
            printf("---------------------------------------------------\n"); \
            printf("Test at %s:%d FAILED\n", \
                __FILE__, this_test.starting_line_number); \
            printf("---------------------------------------------------\n"); \
            printf("  Given: %s\n", this_test.given); \
            printf("   When: %s\n", this_test.when); \
            printf("   Then: %s\n", this_test.then); \
            printf("---------------------------------------------------\n"); \
            printf("FAILED at %s:%d:\n", \
                __FILE__, __LINE__); \
            printf("  ASSERT( %s )\n", #boolean_test); \
            printf("---------------------------------------------------\n"); \
            printf("\n"); \
            return; \
        } \
    } while (0)

/*
    State maintined by clarify during the execution of tests.
*/
typedef struct {
    char * given;                   // The strings describing each
    char * when;                    
    char * then;
    int starting_line_number;       // The starting line number of this
                                    // test (where the GIVEN statement is).
    bool test_executed_this_pass;   // True when a full Given-When-Then test has
                                    // been run on this pass through the function.
    bool skip_this_clause;          // Temp flag used to skip a clause.
                                    
    int current_when_line;          // The starting line of the WHEN clause
                                    // currently being executed.
    int last_then_line_executed;    // The starting line of the most recent THEN
                                    // clause to be executed.
} TEST_CASE;

// Create a unique test function name for each test function, based on the line
// number. We need two levels of indirection to get the line number to be
// evaluated during the string concatentation.
// http://stackoverflow.com/questions/1597007/creating-c-macro-with-and-line-token-concatenation-with-positioning-macr/1597129
#define TOKENPASTE(x, y) x ## y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
#define UNIQUE_TEST_FUNCTION_NAME TOKENPASTE2(test_, __LINE__)

#define PRINT_HEADER() \
    printf("%s: Running Tests...\n", __FILE__);

#define PRINT_RESULTS() \
    printf("\n"); \
    printf("---------------------------------------------------\n"); \
    printf("%s: Test Results\n", __FILE__); \
    printf("---------------------------------------------------\n"); \
    printf("Tested: %d\n", test_count_total); \
    printf("Passed: %d\n", test_count_total - test_count_failed); \
    printf("Failed: %d\n", test_count_failed);

#define RUN_TESTS() \
    TEST_CASE this_test; \
    int test_count_total = 0; \
    int test_count_failed = 0; \
    void all_tests(void); \
    int main(void) {\
        PRINT_HEADER(); \
        all_tests(); \
        PRINT_RESULTS(); \
        return test_count_failed; \
    }\
    void all_tests(void) 

#define GIVEN(precondition) \
    auto void UNIQUE_TEST_FUNCTION_NAME (void); \
    this_test.starting_line_number = __LINE__; \
    this_test.given = precondition; \
    this_test.last_then_line_executed = 0; \
    this_test.current_when_line = 0; \
    do { \
        this_test.test_executed_this_pass = false; \
        UNIQUE_TEST_FUNCTION_NAME(); \
    } while (this_test.test_executed_this_pass); \
    void UNIQUE_TEST_FUNCTION_NAME (void)

#define WHEN(condition) \
    this_test.skip_this_clause = false; \
    if (this_test.test_executed_this_pass) \
    { \
        /* We just completed the last WHEN, switch to this when.*/ \
        this_test.current_when_line = __LINE__; \
        return; \
    } \
    if ((this_test.current_when_line == 0) || (this_test.current_when_line == __LINE__)) \
    { \
        /* This is current when clause, so we're going to run it. */ \
        this_test.when = condition; \
    } \
    else \
    { \
        /* This is not the current WHEN clause... so don't run it. */ \
        this_test.skip_this_clause = true; \
    } \
    if (!this_test.skip_this_clause)

#define THEN(result) \
    this_test.skip_this_clause = false; \
    if (this_test.test_executed_this_pass) \
    { \
        return; \
    } \
    else if (this_test.last_then_line_executed >= __LINE__) \
    { \
        /*We've already run this test, skip it. */ \
        this_test.skip_this_clause = true; \
    } \
    else \
    { \
        /* We are executing this THEN clause this pass. */ \
        this_test.last_then_line_executed = __LINE__; \
        this_test.test_executed_this_pass = true; \
    } \
    if (!this_test.skip_this_clause) \
    { \
        this_test.then = result; \
        test_count_total++; \
    } \
    if (!this_test.skip_this_clause)
    