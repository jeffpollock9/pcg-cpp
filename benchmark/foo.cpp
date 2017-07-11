
#include <benchmark/benchmark.h>

#include <rando.h>

static void
BM_foo(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        const auto f = rando::foo(state.range(0));
        (void)f;
    }
}

BENCHMARK(BM_foo)->Arg(1)->Arg(2)->Arg(3)->Arg(4);

BENCHMARK_MAIN()
