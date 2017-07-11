
#include <gtest/gtest.h>

#include <pcg_random.hpp>
#include <rando.h>

#define RANDO_FIRST_1K_TEST(rng)                                               \
    TEST(rng, first_1k_equal)                                                  \
    {                                                                          \
        const int n = 1000;                                                    \
                                                                               \
        rando::rng rando_rng(1);                                               \
        rng pcg_cpp_rng(1);                                                    \
                                                                               \
        for (int i = 0; i < n; i++)                                            \
        {                                                                      \
            EXPECT_EQ(rando_rng(), pcg_cpp_rng());                             \
        }                                                                      \
    }

RANDO_FIRST_1K_TEST(pcg32)
RANDO_FIRST_1K_TEST(pcg32_fast)
