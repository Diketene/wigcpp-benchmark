cmake_minimum_required(VERSION 3.23)
project(WIGCPP_BENCHMARK)

add_subdirectory(third_party/wigxjpf-1.13)

add_executable(fix_test)
target_sources(fix_test PRIVATE src/fix_test.cpp)

target_compile_features(fix_test PRIVATE cxx_std_20)
target_link_libraries(fix_test PRIVATE wigxjpf)
