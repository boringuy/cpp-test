#include "benchmark/benchmark.h"

#include <sstream>

static void BM_GetLine(benchmark::State& state)
{
    std::istringstream input;
    input.str("1\n2\n3\n4\n5\n6\n7\n");
    for (auto _ : state ) {
        for (std::string line; std::getline(input, line); ) {
            benchmark::DoNotOptimize(line);
        }
    }
}	

BENCHMARK(BM_GetLine);

static void BM_GetLineReuseString(benchmark::State& state)
{
    std::istringstream input;
    input.str("1\n2\n3\n4\n5\n6\n7\n");
    std::string line;
    for (auto _ : state ) {
        for (; std::getline(input, line); ) {
            benchmark::DoNotOptimize(line);
        }
    }
}	

BENCHMARK(BM_GetLineReuseString);

static void BM_GetLineReuseStringClear(benchmark::State& state)
{
    std::istringstream input;
    input.str("1\n2\n3\n4\n5\n6\n7\n");
    std::string line;
    for (auto _ : state ) {
        for (; std::getline(input, line);) {
            benchmark::DoNotOptimize(line);
            line.clear();
        }
    }
}	

BENCHMARK(BM_GetLineReuseStringClear);

static void BM_GetLineReuseStringClearInForStatement(benchmark::State& state)
{
    std::istringstream input;
    input.str("1\n2\n3\n4\n5\n6\n7\n");
    std::string line;
    for (auto _ : state ) {
        for (; std::getline(input, line); line.clear()) {
            benchmark::DoNotOptimize(line);
        }
    }
}	

BENCHMARK(BM_GetLineReuseStringClearInForStatement);
BENCHMARK_MAIN();

