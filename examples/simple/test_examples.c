#include "../../clarify.h"
#include <stdint.h>

RUN_TESTS() {

    GIVEN("some integers") {
        int a = -99;
        int b = -99;
        int c = 99;
        WHEN("I test the ones that are equal") {
            THEN("the test passes") {
                REQUIRE_EQUAL_INT(a, b);
            }
        }
        WHEN("I test the ones that are not equal") {
            THEN("the test fails") {
                REQUIRE_EQUAL_INT(b, c);
            }
        }
    }

    GIVEN("some unsigned integers") {
        unsigned int a = -99;
        unsigned int b = 4294967197; //The unsigned value of -99.
        unsigned int c = 100;
        WHEN("I test the ones that are equal") {
            THEN("the test passes") {
                REQUIRE_EQUAL_UINT(a, b);
            }
        }
        WHEN("I test the ones that are not equal") {
            THEN("the test fails") {
                REQUIRE_EQUAL_UINT(b, c);
            }
        }
    }

    GIVEN("some bytes") {
        uint8_t a = 0x99;
        uint8_t b = 0x99;
        uint8_t c = 0xA0;
        WHEN("I test the ones that are equal") {
            THEN("the test passes") {
                REQUIRE_EQUAL_BYTE(a, b);
            }
        }
        WHEN("I test the ones that are not equal") {
            THEN("the test fails") {
                REQUIRE_EQUAL_BYTE(b, c);
            }
        }
    }

    GIVEN("some strings") {
        char a[] = "the quick brown fox";
        char b[] = "the quick brown fox";
        char c[] = "jumps over the";
        WHEN("I test the ones that are equal") {
            THEN("the test passes") {
                REQUIRE_EQUAL_STRING(a, b);
            }
        }
        WHEN("I test the ones that are not equal") {
            THEN("the test fails") {
                REQUIRE_EQUAL_STRING(b, c);
            }
        }
    }

    GIVEN("some arrays") {
        uint8_t a[] = {1, 2, 3, 4, 5};
        uint8_t b[] = {1, 2, 3, 4, 5};
        uint8_t c[] = {1, 2, 3, 88, 5};
        WHEN("I test the ones that are equal") {
            THEN("the test passes") {
                REQUIRE_EQUAL_MEMORY(a, b, sizeof(a));
            }
        }
        WHEN("I test the ones that are not equal") {
            THEN("the test fails") {
                REQUIRE_EQUAL_MEMORY(b, c, sizeof(b));
            }
        }
    }
}
