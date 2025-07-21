#include "CppUTest/TestHarness.h"
#include "dsp/average.hpp"
#include <cmath>

using dsp::Average;

TEST_GROUP(AverageGroup)
{
    void setup() { }
    void teardown() { }
};

TEST(AverageGroup, Mean)
{
    DOUBLES_EQUAL(3.0f, Average::mean({1,2,3,4,5}), 1e-6);
}