#include "behav.h"

SCENARIO()
{
    GIVEN("two positive integers (1)")
    {
        int a = 5;
        int b = 7;
        
        WHEN ("they are added together")
        {
            int result = a + b;
            
            THEN ("the result is correct")
            {
                ASSERT(result == 12);
                //ASSERT(result == 13);
            }
        }
    }
    
    GIVEN("two positive integers (2)")
    {
        int a = 5;
        int b = 7;
        
        WHEN ("they are multiplied together")
        {
            int result = a * b;
            
            THEN ("the result is correct")
            {
                ASSERT(result == 35);
                //ASSERT(result == 36);
            }
        }
    }
    
    GIVEN ("two negative integers")
    {
        int a = -5;
        int b = -7;
        
        WHEN ("they are multiplied together")
        {
            int result = a * b;
            
            THEN ("the result is correct")
            {
                ASSERT(result == 35);
                //ASSERT(result == -35);
            }
        }
    }
    
    return 0;
}