
#include <gtest/gtest.h>

#include <rando.h>

TEST(pcg32, unique_not_equal)
{
    rando::pcg32_unique rng1(1);
    rando::pcg32_unique rng2(1);
    EXPECT_NE(rng1(), rng2());
}

TEST(pcg64, unique_not_equal)
{
    rando::pcg64_unique rng1(1);
    rando::pcg64_unique rng2(1);
    EXPECT_NE(rng1(), rng2());
}
