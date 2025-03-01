cmake_minimum_required(VERSION 3.30)
project(Black_Scholes_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Black_Scholes_1 main.cpp EuropeanCall.cpp EuropeanPut.cpp Option.cpp MCPricer.cpp)
