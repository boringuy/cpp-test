#include <benchmark/benchmark.h>

#include <vector>

#include "binary_search.h"

static void BM_BinarySearch1(benchmark::State& state) {
  std::vector<int> data;
  data.reserve(10000);

  for (int i = 0; i < 10000; ++i) {
	  data.push_back(i);
  }

  for (auto _ : state) {
    binarySearch(data, 10000);
  }
}

// Register the function as a benchmark
BENCHMARK(BM_BinarySearch1);
// Run the benchmark
BENCHMARK_MAIN();
