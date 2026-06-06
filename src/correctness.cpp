#include "wigcpp/wigcpp.hpp"
#include "wigxjpf.h"
#include <bit>
#include <cstdint>
#include <cstdlib>
#include <format>
#include <iostream>
#include <numeric>
#include <vector>

std::uint64_t ulp_distance(double v1, double v2) {
  auto i1 = std::bit_cast<std::uint64_t>(v1);
  auto i2 = std::bit_cast<std::uint64_t>(v2);
  i1 = (i1 >> 63) ? ~i1 + 1 : i1 | (1UL << 63);
  i2 = (i2 >> 63) ? ~i2 + 1 : i2 | (1UL << 63);
  return i1 > i2 ? i1 - i2 : i2 - i1;
}

auto correctness_3j(int max_two_j) {
  wigcpp::ensure_global(2 * max_two_j, 3);
  std::vector<std::uint64_t> ulp_count;
  ulp_count.reserve(10);
  for (int two_j1 = 0; two_j1 <= max_two_j; ++two_j1) {
    for (int two_j2 = 0; two_j2 <= max_two_j; ++two_j2) {
      for (int two_j3 = std::abs(two_j1 - two_j2); two_j3 <= two_j1 + two_j2; ++two_j3) {
        for (int two_m1 = -two_j1; two_m1 <= two_j1; ++two_m1) {
          for (int two_m2 = -two_j2; two_m2 <= two_j2; ++two_m2) {
            int two_m3 = -(two_m1 + two_m2);
            auto res_wigcpp = wigcpp::three_j(two_j1, two_j2, two_j3, two_m1, two_m2, two_m3);
            auto res_wigxjpf = wig3jj(two_j1, two_j2, two_j3, two_m1, two_m2, two_m3);
            auto ulp = ulp_distance(res_wigcpp, res_wigxjpf);
            if (ulp >= ulp_count.size()) {
              ulp_count.resize(ulp + 1, 0);
            }
            ++ulp_count[ulp];
          }
        }
      }
    }
  }
  return ulp_count;
}

auto correctness_6j(int max_two_j) {
  wigcpp::ensure_global(max_two_j, 6);
  std::vector<std::uint64_t> ulp_count;
  ulp_count.reserve(10);
  for (int two_j1 = 0; two_j1 <= max_two_j; ++two_j1) {
    for (int two_j2 = 0; two_j2 <= max_two_j; ++two_j2) {
      for (int two_j3 = 0; two_j3 <= max_two_j; ++two_j3) {
        for (int two_j4 = 0; two_j4 <= max_two_j; ++two_j4) {
          for (int two_j5 = 0; two_j5 <= max_two_j; ++two_j5) {
            for (int two_j6 = 0; two_j6 <= max_two_j; ++two_j6) {
              auto res_wigcpp = wigcpp::six_j(two_j1, two_j2, two_j3, two_j4, two_j5, two_j6);
              auto res_wigxjpf = wig6jj(two_j1, two_j2, two_j3, two_j4, two_j5, two_j6);
              if (res_wigcpp == 0.0 && res_wigxjpf == 0.0) {
                continue;
              } else if ((res_wigcpp == 0.0 && res_wigxjpf != 0.0) || (res_wigcpp != 0.0 && res_wigxjpf == 0.0))
                  [[unlikely]] {
                std::cout << std::format("result of wigcpp and result of wigxjpf is not both 0. Error occurred in "
                                         "6j({}, {}, {}, {}, {}, {}). Aborted.\n",
                                         two_j1, two_j2, two_j3, two_j4, two_j5, two_j6);
                std::abort();
              }
              auto ulp = ulp_distance(res_wigcpp, res_wigxjpf);
              if (ulp >= ulp_count.size()) {
                ulp_count.resize(ulp + 1, 0);
              }
              ++ulp_count[ulp];
            }
          }
        }
      }
    }
  }
  return ulp_count;
}

auto correctness_9j(int max_two_j) {
  wigcpp::ensure_global(max_two_j, 9);
  std::vector<std::uint64_t> ulp_count;
  ulp_count.reserve(10);
  for (int two_j1 = 0; two_j1 < max_two_j; ++two_j1) {
    for (int two_j2 = 0; two_j2 < max_two_j; ++two_j2) {
      for (int two_j3 = 0; two_j3 < max_two_j; ++two_j3) {
        for (int two_j4 = 0; two_j4 < max_two_j; ++two_j4) {
          for (int two_j5 = 0; two_j5 < max_two_j; ++two_j5) {
            for (int two_j6 = 0; two_j6 < max_two_j; ++two_j6) {
              for (int two_j7 = 0; two_j7 < max_two_j; ++two_j7) {
                for (int two_j8 = 0; two_j8 < max_two_j; ++two_j8) {
                  for (int two_j9 = 0; two_j9 < max_two_j; ++two_j9) {
                    auto res_wigcpp =
                        wigcpp::nine_j(two_j1, two_j2, two_j3, two_j4, two_j5, two_j6, two_j7, two_j8, two_j9);
                    auto res_wigxjpf = wig9jj(two_j1, two_j2, two_j3, two_j4, two_j5, two_j6, two_j7, two_j8, two_j9);
                    if (res_wigcpp == 0.0 && res_wigxjpf == 0.0) {
                      continue;
                    } else if ((res_wigcpp == 0.0 && res_wigxjpf != 0.0) || (res_wigcpp != 0.0 && res_wigxjpf == 0.0))
                        [[unlikely]] {
                      std::cout << std::format(
                          "result of wigcpp and result of wigxjpf is not both 0. Error occurred in "
                          "9j({}, {}, {}, {}, {}, {}, {}, {}, {}). Aborted.\n",
                          two_j1, two_j2, two_j3, two_j4, two_j5, two_j6, two_j7, two_j8, two_j9);
                      std::abort();
                    }
                    auto ulp = ulp_distance(res_wigcpp, res_wigxjpf);
                    if (ulp >= ulp_count.size()) {
                      ulp_count.resize(ulp + 1, 0);
                    }
                    ++ulp_count[ulp];
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ulp_count;
}

void print_ulp_stat(const std::vector<std::uint64_t> &ulp_conut) {
  std::cout << std::format("====== result of ulp count: ======\n");
  auto total_times = std::accumulate(ulp_conut.begin(), ulp_conut.end(), 0);
  for (auto i = 0UL; i < ulp_conut.size(); ++i) {
    const auto times = ulp_conut[i];
    double precent = static_cast<double>(times) / total_times;
    std::cout << std::format("Ulp: {}, percent: {}\n", i, precent);
  }
}
auto main(void) -> int {
  wig_table_init(200 * 2, 9);
  wig_temp_init(200 * 2);

  auto result = correctness_3j(30);
  std::cout << std::format("result of 3j correctness test:\n");
  print_ulp_stat(result);

  result = correctness_6j(30);
  std::cout << std::format("result of 6j correctness test:\n");
  print_ulp_stat(result);

  result = correctness_9j(12);
  std::cout << std::format("result of 9j correctness test:\n");
  print_ulp_stat(result);

  wig_temp_free();
  wig_table_free();
}