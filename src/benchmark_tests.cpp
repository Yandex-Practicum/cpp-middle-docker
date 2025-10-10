#include <algorithm>
#include <benchmark/benchmark.h>
#include <deque>
#include <flat_set>
#include <list>
#include <numeric>
#include <print>
#include <random>
#include <ranges>
#include <vector>

// ----------------- std::list -----------------
static void BM_ListInsert(benchmark::State &state) {
    const auto size = state.range(0);  // get 1st arg
    for (auto _ : state) {
        std::list<int> list;
        for (auto i : std::views::iota(0, size)) {
            list.push_back(i);
        }
        benchmark::DoNotOptimize(list);
    }
}

// ----------------- std::vector -----------------
static void BM_VectorInsert(benchmark::State &state) {
    const auto size = state.range(0);             // get 1st arg
    const bool b_use_reserve = !!state.range(1);  // get 2nd arg
    for (auto _ : state) {
        std::vector<int> vec;

        if (b_use_reserve) {
            vec.reserve(size);
        }

        for (auto i : std::views::iota(0, size)) {
            vec.push_back(i);
        }
        benchmark::DoNotOptimize(vec);
    }
}

// ----------------- std::deque -----------------
static void BM_DequeInsert(benchmark::State &state) {
    const auto size = state.range(0);  // get 1st arg
    for (auto _ : state) {
        std::deque<int> deq;
        for (auto i : std::views::iota(0, size)) {
            deq.push_back(i);
        }
        benchmark::DoNotOptimize(deq);
    }
}

BENCHMARK(BM_DequeInsert)
    ->Unit(benchmark::kMicrosecond)  //
    ->Arg(1000)
    ->Arg(10000)
    ->Arg(100000)
    ->Arg(1000000);

BENCHMARK(BM_ListInsert)
    ->Unit(benchmark::kMicrosecond)  //
    ->Range(1000, 1'000'000)
    ->Iterations(20);

BENCHMARK(BM_VectorInsert)
    ->Unit(benchmark::kMicrosecond)  //
    ->Ranges({{1000, 1'000'000}, {0, 1}})
    ->ArgNames({"size", "Use reserve() method"});

// ----------------- Точка входа для Google Benchmark -----------------
BENCHMARK_MAIN();
