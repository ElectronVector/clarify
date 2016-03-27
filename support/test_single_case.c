#include "../clarify.h"

RUN_TESTS()
{
    GIVEN("A")
    {
        printf("+ Given: A\n");
        
        WHEN("1")
        {
            printf(" + When: 1\n");

            /* THEN */
            THEN("a")
            {
                printf("  + Then: a\n");
            }
        }
    }
}