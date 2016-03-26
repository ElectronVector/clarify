#include "../../clarify.h"
#include "power_button.h"
#include <string.h>

RUN_TESTS() {
    GIVEN("the power is off") {
        power_button_initialize(POWER_OFF);

        WHEN("nothing happens") {

            THEN("the power is still off") {
                ASSERT(power_button_getPowerState() == POWER_OFF);
            }
        }

        WHEN("the power button is momentarily pressed") {
            power_button_pressMomentary();

            THEN("the power turns on") {
                ASSERT(power_button_getPowerState() == POWER_ON);
            }
        }
    }
    
    GIVEN("the power is on") {
        power_button_initialize(POWER_OFF);
        power_button_pressMomentary();      // Turn the power on.

        WHEN("the power button is momentarily pressed") {
            power_button_pressMomentary();

            THEN("the power remains on") {
                ASSERT(power_button_getPowerState() == POWER_ON);
            }
        }

        WHEN("the power button is held down") {
            power_button_pressHold();

            THEN("the power turns off") {
                ASSERT(power_button_getPowerState() == POWER_OFF);
            }
        }
    }
}
