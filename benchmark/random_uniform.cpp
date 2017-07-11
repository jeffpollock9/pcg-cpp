
#include <benchmark/benchmark.h>

#include <rando.h>
#include <random>

struct fixture : benchmark::Fixture
{
    using real_type = double;
    std::uniform_real_distribution<real_type> runif;
    real_type x;
};

#define RANDO_UNIFORM_BENCHMARK(RNG)                                           \
    BENCHMARK_F(fixture, BM_##RNG)(benchmark::State & state)                   \
    {                                                                          \
        RNG rng;                                                               \
        while (state.KeepRunning())                                            \
        {                                                                      \
            benchmark::DoNotOptimize(x = runif(rng));                          \
        }                                                                      \
    }

using namespace std;
using namespace rando;

RANDO_UNIFORM_BENCHMARK(mt19937_64)
RANDO_UNIFORM_BENCHMARK(mt19937)
RANDO_UNIFORM_BENCHMARK(pcg32_fast)
RANDO_UNIFORM_BENCHMARK(pcg64_fast)
RANDO_UNIFORM_BENCHMARK(pcg32)
RANDO_UNIFORM_BENCHMARK(pcg64)

BENCHMARK_MAIN()
