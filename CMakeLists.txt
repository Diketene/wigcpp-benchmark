cmake_minimum_required(VERSION 3.23)
project(WIGCPP_BENCHMARK LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(third_party/wigxjpf-1.13)
add_subdirectory(../wigcpp ${CMAKE_CURRENT_BINARY_DIR}/wigcpp)

include(FetchContent)
FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG v3.12.0
)

FetchContent_MakeAvailable(nlohmann_json)

add_executable(fix_test)
target_sources(fix_test PRIVATE src/fix_test.cpp)

target_compile_features(fix_test PRIVATE cxx_std_20)
target_link_libraries(fix_test PRIVATE wigxjpf)

add_executable(correctness)
target_sources(correctness PRIVATE src/correctness.cpp)

target_compile_features(correctness PRIVATE cxx_std_20)
target_link_libraries(correctness PRIVATE wigxjpf wigcpp::wigcpp)

add_executable(benchmark)
target_sources(benchmark PRIVATE src/benchmark.cpp)

target_compile_features(benchmark PRIVATE cxx_std_20)
target_link_libraries(benchmark PRIVATE wigxjpf wigcpp::wigcpp nlohmann_json::nlohmann_json)
