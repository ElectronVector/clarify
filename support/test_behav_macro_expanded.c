/*
    This is a test file used during development. This is where I've worked out
    most of the code should look like after the macros are expanded.
*/

#include "behav.h"

SCENARIO()
{
    auto void test_5 (void);
    this_test.starting_line_number = 5;
    this_test.given = "two positive integers (1)";
    this_test.last_then_line_executed = 0;
    this_test.current_when_line = 0;
    
    do {
        this_test.test_executed_this_pass = false;
        test_5();
    } while(this_test.test_executed_this_pass);
    
    void test_5 (void)
    {
        printf("+ Given: two positive integers (1)\n");
        int a = 5;
        int b = 7;
        
        /* WHEN */
        this_test.skip_this_clause = false;
        if (this_test.test_executed_this_pass)
        {
            //We just completed the last WHEN, switch to this when.
            this_test.current_when_line = 22;
            return;
        }
        if ((this_test.current_when_line == 0) || (this_test.current_when_line == 22))
        {
            //This is current when clause, so we're going to run it.
            this_test.when = "they are added together";
        }
        else
        {
            //This is not the current WHEN clause... so don't run it.
            this_test.skip_this_clause = true;
        }
        if (!this_test.skip_this_clause)
        {
            printf(" + When: they are added together\n");
            int result = a + b;

            /* THEN */
            this_test.skip_this_clause = false;
            if (this_test.test_executed_this_pass)
            {
                return;
            }
            else if (this_test.last_then_line_executed >= __LINE__)
            {
                //We've already run this test, skip it.
                this_test.skip_this_clause = true;
            }
            else
            {
                // We are executing this THEN clause this pass.
                this_test.last_then_line_executed = __LINE__;
                this_test.test_executed_this_pass = true;
            }
            if (!this_test.skip_this_clause)
            {
                this_test.then = "the result is correct";
                test_count_total++;
            }
            if (!this_test.skip_this_clause)
            {
                printf("  + Then: the result is correct\n");
                ASSERT(result == 12);
                //ASSERT(result == 13); // A failure is going to cause an exit immediately.
                
                //change the state
                b = 8;
            }
            
            /* THEN */
            this_test.skip_this_clause = false;
            if (this_test.test_executed_this_pass)
            {
                return;
            }
            else if (this_test.last_then_line_executed >= __LINE__)
            {
                //We've already run this test, skip it.
                this_test.skip_this_clause = true;
            }
            else
            {
                // We are executing this THEN clause this pass.
                this_test.last_then_line_executed = __LINE__;
                this_test.test_executed_this_pass = true;
            }
            if (!this_test.skip_this_clause)
            {
                this_test.then = "then something else happens";
                test_count_total++;
            }
            if (!this_test.skip_this_clause)
            {
                printf("  + Then: something else happens\n");
                ASSERT(result == 12);
                //ASSERT(result == 13); // A failure is going to cause an exit immediately.
                
                //change the state
                b = 8;
            }
        }

        /* WHEN */
        this_test.skip_this_clause = false;
        if (this_test.test_executed_this_pass)
        {
            //We just completed the last WHEN, switch to this when.
            this_test.current_when_line = 109;
            return;
        }
        if ((this_test.current_when_line == 0) || (this_test.current_when_line == 109))
        {
            //This is current when clause, so we're going to run it.
            this_test.when = "they are multiplied together";
        }
        else
        {
            //This is not the current when line... so don't run it.
            this_test.skip_this_clause = true;
        }
        if (!this_test.skip_this_clause)
        {
            printf(" + When: they are multiplied together\n");
            int result = a * b;
        
            /* THEN */
            this_test.skip_this_clause = false;
            if (this_test.test_executed_this_pass)
            {
                return;
            }
            else if (this_test.last_then_line_executed >= __LINE__)
            {
                //We've already run this test, skip it.
                this_test.skip_this_clause = true;
            }
            else
            {
                // We are executing this THEN clause this pass.
                this_test.last_then_line_executed = __LINE__;
                this_test.test_executed_this_pass = true;
            }
            if (!this_test.skip_this_clause)
            {
                this_test.then = "the value is correct";
                test_count_total++;
            }
            if (!this_test.skip_this_clause)
            {
                printf("  + Then: the value is correct\n");
                ASSERT(result == 35);
            }
        }
    }
    
    // GIVEN("two positive integers (1)")
    // {
    //     int a = 5;
    //     int b = 7;
    //     
    //     WHEN ("they are added together")
    //     {
    //         int result = a + b;
    //         
    //         THEN ("the result is correct")
    //         {
    //             ASSERT(result == 12);
    //             ASSERT(result == 13);
    //         }
    //     }
    //     
    //     WHEN ("they are multiplied together")
    //     {
    //         int result = a * b;
    //         
    //         THEN ("the result is correct")
    //         {
    //             ASSERT(result == 35);
    //             //ASSERT(result == 36);
    //         }
    //     }
    // }
    
//     GIVEN("two positive integers (2)")
//     {
//         int a = 5;
//         int b = 7;
//         
//         WHEN ("they are multiplied together")
//         {
//             int result = a * b;
//             
//             THEN ("the result is correct")
//             {
//                 ASSERT(result == 35);
//                 //ASSERT(result == 36);
//             }
//         }
//     }
//     
//     GIVEN ("two negative integers")
//     {
//         int a = -5;
//         int b = -7;
//         
//         WHEN ("they are multiplied together")
//         {
//             int result = a * b;
//             
//             THEN ("the result is correct")
//             {
//                 ASSERT(result == 35);
//                 //ASSERT(result == -35);
//             }
//         }
//     }
}