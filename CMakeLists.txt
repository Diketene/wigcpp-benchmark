cmake_minimum_required(VERSION 3.23)
project(WIGCPP_BENCHMARK LANGUAGES CXX)

add_subdirectory(third_party/wigxjpf-1.13)
add_subdirectory(../wigcpp ${CMAKE_CURRENT_BINARY_DIR}/wigcpp)

add_executable(fix_test)
target_sources(fix_test PRIVATE src/fix_test.cpp)

target_compile_features(fix_test PRIVATE cxx_std_20)
target_link_libraries(fix_test PRIVATE wigxjpf)

add_executable(correctness)
target_sources(correctness PRIVATE src/correctness.cpp)

target_compile_features(correctness PRIVATE cxx_std_20)
target_link_libraries(correctness PRIVATE wigxjpf wigcpp::wigcpp)
