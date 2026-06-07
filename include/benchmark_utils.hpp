#ifndef WIGCPP_BENCHMARK_UTILS
#define WIGCPP_BENCHMARK_UTILS

#include <algorithm>
#include <array>
#include <chrono>

namespace wigcpp::benchmark {

template <typename F> double benchmark(F &&func, std::uint64_t &total_calls) {
  using clock = std::chrono::high_resolution_clock;
  auto start = clock::now();

  func(total_calls);

  auto end = clock::now();
  return std::chrono::duration<double>(end - start).count();
}

template <int Runs, typename F> double benchmark_median(F &&func, std::uint64_t &total_calls) {
  static_assert(Runs >= 3, "Runs must be >= 3");

  std::array<double, Runs - 1> times;

  std::uint64_t calls_acc = 0;

  for (int i = 0; i < Runs; ++i) {
    std::uint64_t calls = 0;
    volatile double t = benchmark(func, calls);
    calls_acc += calls;
    if (i == 0)
      continue;
    times[i - 1] = t;
  }

  auto mid = times.begin() + times.size() / 2;

  std::nth_element(times.begin(), mid, times.end());

  total_calls = calls_acc / static_cast<std::uint64_t>(Runs);

  return *mid;
}

} // namespace wigcpp::benchmark

#endif