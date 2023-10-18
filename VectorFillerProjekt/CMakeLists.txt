cmake_minimum_required(VERSION 3.25)
project(VectorFillerProjekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorFillerProjekt main.cpp src/generators/Generator.h src/time/Stopwatch.h src/collection_utils/VectorFactory.h src/client/VectorClient.h src/client/impl/VectorClientImpl.h src/bootstrap/Bootstrap.h)
