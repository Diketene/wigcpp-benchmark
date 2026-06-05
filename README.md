# wigcpp benchmark
This is the repository of wigcpp's benchmark. Since wigxjpf does not provide a cross-platform build system, this repository can only be built on Unix-like system (e.g., Linux or macOS).

## If you want to build this project

For developer convenience, this repository must be placed in the same directory as wigcpp. Use `cd wigcpp-benchmark`, then `cmake -B build && cmake --build build` to build this project.

## The usage of source files

Here lists the purpose of each source file.

</div align="center">

|file|purpose|
|:-:|:-:|
|`fix_test.cpp`|provides true values calculated by wigxjpf which are consumed by wigcpp's test|
|`correctness.cpp`|provides the correctness tests between wigcpp and wigxjpf| 

</div>

## What's More
This repository vendors wigxjpf 1.13. The [`CMakeLists.txt`](third_party/wigxjpf-1.13/CMakeLists.txt) of wigxjpf was modefied by simply adding `cmake_minimum_required` and `project`.
