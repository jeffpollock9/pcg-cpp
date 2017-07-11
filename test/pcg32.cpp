
#include <gtest/gtest.h>

#include <pcg_random.hpp>
#include <rando.h>

TEST(first_1k_equal, pcg32)
{
    const int n = 1000;

    rando::pcg32 rando_rng(1);
    pcg32 pcg_cpp_rng(1);

    for (int i = 0; i < n; i++)
    {
        EXPECT_EQ(rando_rng(), pcg_cpp_rng());
    }
}
