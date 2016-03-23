#include <stdio.h>

#define ASSERT(boolean_test) \
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

typedef struct {
    int starting_line_number;
    char * given;
    char * when;
    char * then;
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

#define SCENARIO() \
    TEST_CASE this_test; \
    int test_count_total = 0; \
    int test_count_failed = 0; \
    int all_tests(void); \
    int main(int argc, char **argv) {\
        PRINT_HEADER(); \
        all_tests(); \
        PRINT_RESULTS(); \
        return test_count_failed; \
    }\
    int all_tests(void) 

#define GIVEN(precondition) \
    auto void UNIQUE_TEST_FUNCTION_NAME (void); \
    this_test.starting_line_number = __LINE__; \
    this_test.given = precondition; \
    UNIQUE_TEST_FUNCTION_NAME(); \
    void UNIQUE_TEST_FUNCTION_NAME (void)

#define WHEN(condition) this_test.when = condition;

#define THEN(result) \
    this_test.then = result; \
    test_count_total++;
    