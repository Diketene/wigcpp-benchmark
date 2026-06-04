#include "wigxjpf.h"
#include <format>
#include <iostream>

int main() {
  wig_table_init(2 * 2000, 9);
  wig_temp_init(2 * 2000);

  auto res = wig3jj(2 * 1, 2 * 2, 3 * 2, 0, 0, 0);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig3jj(2 * 1.5, 2 * 3.5, 2 * 5, 2 * 0.5, -2 * 0.5, 0);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig3jj(2 * 400, 2 * 80, 2 * 480, 2 * 1, -1 * 2, 0);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig3jj(2000, 200, 1900, -200, 60, 140);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig3jj(1001, 100, 971, 101, 40, -141);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig3jj(1007, 100, 971, -115, -40, 155);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig3jj(0, 0, 0, 0, 0, 0);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig3jj(2, 3, 4, 0, 0, 0);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig3jj(2, 2, 4, 1, 1, 1);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig3jj(2, 4, 8, 0, 0, 0);
  std::cout << std::format("{:.17e}", res) << '\n';

  std::cout << std::format("===============\n", res);

  res = wig6jj(2 * 2, 2 * 2, 2 * 2, 2 * 2, 2 * 2, 2 * 2);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig6jj(2 * 1, 2 * 2, 2 * 3, 2 * 1, 2 * 2, 2 * 3);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig6jj(0, 0, 0, 0, 0, 0);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig6jj(2 * 20, 2 * 20, 2 * 20, 2 * 20, 2 * 20, 2 * 20);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig6jj(2 * 20, 2 * 20, 2 * 20, 2 * 20, 2 * 20, 0);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig6jj(2, 4, 6, 4, 2, 4);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig6jj(1, 1, 2, 1, 1, 2);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig6jj(4, 4, 10, 4, 4, 4);
  std::cout << std::format("{:.17e}", res) << '\n';

  std::cout << std::format("================\n");

  res = wig9jj(2 * 2, 2 * 2, 2 * 2, 2 * 2, 2 * 2, 2 * 2, 2 * 2, 2 * 2, 2 * 2);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig9jj(0, 0, 0, 0, 0, 0, 0, 0, 0);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig9jj(8, 8, 8, 8, 8, 8, 8, 8, 8);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig9jj(2 * 4, 2 * 4, 2 * 4, 2 * 4, 2 * 4, 2 * 4, 2 * 4, 2 * 4, 0);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig9jj(2 * 20, 2 * 20, 2 * 20, 2 * 20, 2 * 20, 2 * 20, 2 * 20, 2 * 20,
               2 * 20);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig9jj(1, 1, 0, 1, 3, 2, 0, 2, 2);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig9jj(60, 60, 20, 61, 61, 40, 61, 61, 20);
  std::cout << std::format("{:.17e}", res) << '\n';

  res = wig9jj(30, 30, 30, 30, 6, 30, 30, 36, 20);
  std::cout << std::format("{:.17e}", res) << '\n';

  wig_temp_free();
  wig_table_free();
}