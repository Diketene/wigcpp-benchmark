cmake_minimum_required(VERSION 3.23)
project(WIGCPP_BENCHMARK LANGUAGES CXX C)

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

set(WIGCPP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../wigcpp")
find_package(Git REQUIRED)
if(GIT_FOUND AND EXISTS "${WIGCPP_DIR}/.git")
  execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
    WORKING_DIRECTORY ${WIGCPP_DIR}
    OUTPUT_VARIABLE GIT_COMMIT
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )

  execute_process(
    COMMAND ${GIT_EXECUTABLE} diff --quiet
    WORKING_DIRECTORY ${WIGCPP_DIR}
    RESULT_VARIABLE GIT_IS_DIRTY
  )

  if(GIT_IS_DIRTY EQUAL 0)
    set(GIT_DIRTY "false")
  else()
    set(GIT_DIRTY "true")
  endif()

else()
  set(GIT_COMMIT "unknown")
  set(GIT_DIRTY "unknown")
endif()

add_executable(fix_test)
target_sources(fix_test PRIVATE src/fix_test.cpp)

target_compile_features(fix_test PRIVATE cxx_std_20)
target_link_libraries(fix_test PRIVATE wigxjpf)

add_executable(correctness)
target_sources(correctness PRIVATE src/correctness.cpp)

target_compile_features(correctness PRIVATE cxx_std_20)
target_link_libraries(correctness PRIVATE wigxjpf wigcpp::wigcpp)

add_executable(baseline)
target_sources(baseline PRIVATE src/baseline.cpp)
target_include_directories(baseline PRIVATE include)

target_compile_features(baseline PRIVATE cxx_std_20)
target_compile_definitions(baseline PRIVATE
  WIGCPP_GIT_COMMIT="${GIT_COMMIT}"
  WIGCPP_GIT_DIRTY=${GIT_DIRTY}
)

target_link_libraries(baseline PRIVATE wigxjpf wigcpp::wigcpp nlohmann_json::nlohmann_json)
