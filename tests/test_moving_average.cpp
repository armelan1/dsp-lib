#include "CppUTest/TestHarness.h"
#include "dsp/moving_average.hpp"

using dsp::MovingAverage;

TEST_GROUP(MovingAverageGroup)
{
    void setup() { }
    void teardown() { }
};

TEST(MovingAverageGroup, StartsEmpty)
{
    MovingAverage ma(4);
    CHECK_FALSE(ma.ready());
    DOUBLES_EQUAL(0.0f, ma.value(), 1e-6);
}

TEST(MovingAverageGroup, AccumulatesUntilFull)
{
    MovingAverage ma(4);
    ma.push(1.0f);
    ma.push(3.0f);
    DOUBLES_EQUAL(2.0f, ma.value(), 1e-6);
    CHECK_FALSE(ma.ready());
}

TEST(MovingAverageGroup, RollingWindow)
{
    MovingAverage ma(4);
    ma.push(1);
    ma.push(2);
    ma.push(3);
    ma.push(4);
    CHECK(ma.ready());
    DOUBLES_EQUAL(2.5f, ma.value(), 1e-6);

    ma.push(5);
    DOUBLES_EQUAL(3.5f, ma.value(), 1e-6);
}
