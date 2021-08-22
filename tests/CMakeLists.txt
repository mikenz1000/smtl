cmake_minimum_required(VERSION 2.8)

file(GLOB test_src
        "*.cpp"
        )

file(GLOB test_header
        "../include/*.h"
        )

include_directories(../include)

add_library(test ${test_src} ${test_header})