
set(RANDO_BENCHMARKS
    random_uniform)

foreach (benchmark ${RANDO_BENCHMARKS})
    set(BENCHMARK_NAME "${benchmark}_benchmark")
    add_executable(${BENCHMARK_NAME} ${benchmark}.cpp)
    target_link_libraries(${BENCHMARK_NAME} benchmark rando)
endforeach ()
