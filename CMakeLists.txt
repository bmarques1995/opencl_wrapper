cmake_minimum_required(VERSION 3.10)

project(opencl_wrapper LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(vendor/opencl_headers)
add_subdirectory(vendor/opencl_loader)
add_subdirectory(vendor/opencl_hpp)

add_library(opencl_wrapper STATIC src/OpenCLWrapperLog.cpp src/OpenCLWrapperLog.hpp)

target_include_directories(opencl_wrapper PUBLIC ./vendor/opencl_headers ./vendor/opencl_hpp)
target_link_libraries(opencl_wrapper PRIVATE OpenCL)