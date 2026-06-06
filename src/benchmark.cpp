#include "wigcpp/wigcpp.hpp"
#include "wigxjpf.h"
#include <chrono>
#include <cstdint>
#include <cstdlib>

template <typename F> double benchmark(F &&func, std::uint64_t &total_calls) {
  using clock = std::chrono::high_resolution_clock;
  auto start = clock::now();

  func(total_calls);

  auto end = clock::now();
  return std::chrono::duration<double>(end - start).count();
}

auto benchmark_3j(int max_two_j) {
  wigcpp::ensure_global(2 * max_two_j, 3);

  std::uint64_t calls = 0;

  auto elapsed = benchmark(
      [&](std::uint64_t &calls) {
        for (int two_j1 = 0; two_j1 <= max_two_j; ++two_j1) {
          for (int two_j2 = 0; two_j2 <= max_two_j; ++two_j2) {
            for (int two_j3 = std::abs(two_j1 - two_j2); two_j3 <= two_j1 + two_j2; ++two_j3) {
              for (int two_m1 = -two_j1; two_m1 <= two_j1; ++two_m1) {
                for (int two_m2 = -two_j2; two_m2 <= two_j2; ++two_m2) {
                  int two_m3 = -(two_m1 + two_m2);
                  volatile double r = wigcpp::three_j(two_j1, two_j2, two_j3, two_m1, two_m2, two_m3);
                  ++calls;
                }
              }
            }
          }
        }
      },
      calls);

  return std::make_pair(elapsed, calls);
}

auto benchmark_3j_wigxjpf(int max_two_j) {
  std::uint64_t calls = 0;

  auto elapsed = benchmark(
      [&](std::uint64_t &calls) {
        for (int two_j1 = 0; two_j1 <= max_two_j; ++two_j1) {
          for (int two_j2 = 0; two_j2 <= max_two_j; ++two_j2) {
            for (int two_j3 = std::abs(two_j1 - two_j2); two_j3 <= two_j1 + two_j2; ++two_j3) {
              for (int two_m1 = -two_j1; two_m1 <= two_j1; ++two_m1) {
                for (int two_m2 = -two_j2; two_m2 <= two_j2; ++two_m2) {
                  int two_m3 = -(two_m1 + two_m2);
                  volatile double r = wig3jj(two_j1, two_j2, two_j3, two_m1, two_m2, two_m3);
                  ++calls;
                }
              }
            }
          }
        }
      },
      calls);

  return std::make_pair(elapsed, calls);
}

auto benchmark_6j(int max_two_j) {
  wigcpp::ensure_global(max_two_j, 6);

  std::uint64_t calls = 0;

  auto elaspsed = benchmark(
      [&](std::uint64_t &calls) {
        for (int two_j1 = 0; two_j1 <= max_two_j; ++two_j1) {
          for (int two_j2 = 0; two_j2 <= max_two_j; ++two_j2) {
            for (int two_j3 = 0; two_j3 <= max_two_j; ++two_j3) {
              for (int two_j4 = 0; two_j4 <= max_two_j; ++two_j4) {
                for (int two_j5 = 0; two_j5 <= max_two_j; ++two_j5) {
                  for (int two_j6 = 0; two_j6 <= max_two_j; ++two_j6) {
                    volatile double r = wigcpp::six_j(two_j1, two_j2, two_j3, two_j4, two_j5, two_j6);
                    ++calls;
                  }
                }
              }
            }
          }
        }
      },
      calls);

  return std::make_pair(elaspsed, calls);
}

auto benchmark_6j_wigxjpf(int max_two_j) {
  std::uint64_t calls = 0;

  auto elaspsed = benchmark(
      [&](std::uint64_t &calls) {
        for (int two_j1 = 0; two_j1 <= max_two_j; ++two_j1) {
          for (int two_j2 = 0; two_j2 <= max_two_j; ++two_j2) {
            for (int two_j3 = 0; two_j3 <= max_two_j; ++two_j3) {
              for (int two_j4 = 0; two_j4 <= max_two_j; ++two_j4) {
                for (int two_j5 = 0; two_j5 <= max_two_j; ++two_j5) {
                  for (int two_j6 = 0; two_j6 <= max_two_j; ++two_j6) {
                    volatile double r = wig6jj(two_j1, two_j2, two_j3, two_j4, two_j5, two_j6);
                    ++calls;
                  }
                }
              }
            }
          }
        }
      },
      calls);

  return std::make_pair(elaspsed, calls);
}

auto benchmark_9j(int max_two_j) {
  wigcpp::ensure_global(max_two_j, 9);

  std::uint64_t calls = 0;

  auto elaspsed = benchmark(
      [&](std::uint64_t &calls) {
        for (int two_j1 = 0; two_j1 <= max_two_j; ++two_j1) {
          for (int two_j2 = 0; two_j2 <= max_two_j; ++two_j2) {
            for (int two_j3 = 0; two_j3 <= max_two_j; ++two_j3) {
              for (int two_j4 = 0; two_j4 <= max_two_j; ++two_j4) {
                for (int two_j5 = 0; two_j5 <= max_two_j; ++two_j5) {
                  for (int two_j6 = 0; two_j6 <= max_two_j; ++two_j6) {
                    for (int two_j7 = 0; two_j7 <= max_two_j; ++two_j7) {
                      for (int two_j8 = 0; two_j8 <= max_two_j; ++two_j8) {
                        for (int two_j9 = 0; two_j9 <= max_two_j; ++two_j9) {
                          volatile double r = wigcpp::nine_j(two_j1, two_j2, two_j3, two_j4, two_j5, two_j6, two_j7, two_j8, two_j9);
                          ++calls;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      },
      calls);

  return std::make_pair(elaspsed, calls);
}

auto benchmark_9j_wigxjpf(int max_two_j) {
  std::uint64_t calls = 0;

  auto elaspsed = benchmark(
      [&](std::uint64_t &calls) {
        for (int two_j1 = 0; two_j1 <= max_two_j; ++two_j1) {
          for (int two_j2 = 0; two_j2 <= max_two_j; ++two_j2) {
            for (int two_j3 = 0; two_j3 <= max_two_j; ++two_j3) {
              for (int two_j4 = 0; two_j4 <= max_two_j; ++two_j4) {
                for (int two_j5 = 0; two_j5 <= max_two_j; ++two_j5) {
                  for (int two_j6 = 0; two_j6 <= max_two_j; ++two_j6) {
                    for (int two_j7 = 0; two_j7 <= max_two_j; ++two_j7) {
                      for (int two_j8 = 0; two_j8 <= max_two_j; ++two_j8) {
                        for (int two_j9 = 0; two_j9 <= max_two_j; ++two_j9) {
                          volatile double r = wig9jj(two_j1, two_j2, two_j3, two_j4, two_j5, two_j6, two_j7, two_j8, two_j9);
                          ++calls;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      },
      calls);

  return std::make_pair(elaspsed, calls);
}