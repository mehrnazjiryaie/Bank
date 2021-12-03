cmake_minimum_required(VERSION 3.0)
project(main)
add_executable(app src/main.cpp src/Bank.cpp src/Transaction.cpp)
include_directories(include)