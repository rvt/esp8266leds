#include <basiceffects.h>
#include <catch2/catch.hpp>
#include <hsb.h>

SCENARIO("Rainboweffect will change based on time", "[rainbow]") {
    GIVEN("A rainbow filter at 300 seconds") {
        RainbowEffect rainbow(0.f, 300.f, 300.f * 1000);
        WHEN("at start time with no hue offset") {
            THEN("colors shuld be initial hue at time when filter was started") {
                HSB hsb = rainbow.handleEffect(0, 300 * 1000 + 00 * 1000, HSB(20.0f, 0.0f,  0.0f,  0.0f,  0.0f));
                REQUIRE(hsb.hue() == Approx(0.0f));
            }
            THEN("colors shuld be at 13.2 (handle fractions, (11/300)*360)") {
                HSB hsb = rainbow.handleEffect(0, 300 * 1000 + 11 * 1000, HSB(20.0f, 0.0f,  0.0f,  0.0f,  0.0f));
                REQUIRE(hsb.hue() == Approx(13.2f));
            }
            THEN("colors shuld be at green ") {
                HSB hsb = rainbow.handleEffect(0, 300 * 1000 + 100 * 1000, HSB(20.0f, 0.0f,  0.0f,  0.0f,  0.0f));
                REQUIRE(hsb.hue() == Approx(120.0f));
            }
            THEN("colors shuld be at blue ") {
                HSB hsb = rainbow.handleEffect(0, 300 * 1000 + 200 * 1000, HSB(20.0f, 0.0f,  0.0f,  0.0f,  0.0f));
                REQUIRE(hsb.hue() == Approx(240.0f));
            }
            THEN("colors shuld be at final state ") {
                HSB hsb = rainbow.finalState(0, 300 * 1000 + 200 * 1000, HSB(20.0f, 0.0f,  0.0f,  0.0f,  0.0f));
                REQUIRE(hsb.hue() == Approx(240.0f));
            }
        }
    }
    GIVEN("A rainbow filter at 300 seconds") {
        RainbowEffect rainbow(30.f, 300, 1000000);
        WHEN("at start time with hue offset of 30") {
            THEN("colors shuld be initial hue at time when filter was started") {
                HSB hsb = rainbow.handleEffect(0, 1000000, HSB(20.0f, 0.0f,  0.0f,  0.0f,  0.0f));
                REQUIRE(hsb.hue() == Approx(30.0f));
            }
            THEN("colors shuld be at green ") {
                HSB hsb = rainbow.handleEffect(0, 1100000, HSB(20.0f, 0.0f,  0.0f,  0.0f,  0.0f));
                REQUIRE(hsb.hue() == Approx(150.0f));
            }
            THEN("colors shuld be at blue ") {
                HSB hsb = rainbow.handleEffect(0, 1200000, HSB(20.0f, 0.0f,  0.0f,  0.0f,  0.0f));
                REQUIRE(hsb.hue() == Approx(270.0f));
            }
        }
    }
}