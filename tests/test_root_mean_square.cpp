#include "CppUTest/TestHarness.h"
#include "dsp/root_mean_square.hpp"
#include <cmath>

using dsp::RootMeanSquare;

TEST_GROUP(RMSGroup)
{
    void setup() { }
    void teardown() { }
};

TEST(RMSGroup, StartsEmpty)
{
    RootMeanSquare rms(4);
    CHECK_FALSE(rms.ready());
    DOUBLES_EQUAL(0.0f, rms.value(), 1e-6);
}

TEST(RMSGroup, AccumulatesAndComputesRMS)
{
    RootMeanSquare rms(2);
    rms.push(3.0f);   // RMS = sqrt(9) = 3
    rms.push(4.0f);   // RMS = sqrt((9 + 16)/2) = 3.5
    CHECK(rms.ready());
    DOUBLES_EQUAL(std::sqrt(12.5f), rms.value(), 1e-6);
}

TEST(RMSGroup, RollsCorrectly)
{
    RootMeanSquare rms(3);
    rms.push(3);  // 9
    rms.push(4);  // 16
    rms.push(0);  // 0
    rms.push(0);  // replaces 9 → RMS = sqrt((16 + 0 + 0)/3) = ~2.309
    DOUBLES_EQUAL(std::sqrt((16 + 0 + 0) / 3.0f), rms.value(), 1e-6);
}
