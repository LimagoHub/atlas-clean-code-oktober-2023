cmake_minimum_required(VERSION 3.25)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Calculator main.cpp math/CalculatorImpl.h math/Calculator.cpp math/Calculator.h math/CalculatorLogger.h Client.h math/CalculatorSecure.h math/CalculatorFactory.h)
