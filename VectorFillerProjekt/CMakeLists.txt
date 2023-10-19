cmake_minimum_required(VERSION 3.25)
project(VectorFillerProjekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorFillerProjekt main.cpp src/generators/Generator.h src/time/Stopwatch.h src/collection_utils/VectorFactory.h src/client/VectorClient.h src/client/impl/VectorClientImpl.h src/bootstrap/Bootstrap.h src/generators/impl/random/mersenne_twister_number_generator.h src/generators/number_generator.h src/collection_utils/AbstractVectorFactory.h src/collection_utils/impl/sequential/VectorFactorySequentialImpl.h src/time/StopwatchImpl.h src/collection_utils/impl/decorators/AbstractVectorFactoryDecorator.h src/collection_utils/impl/decorators/VectorFactoryBenchmarkDecorator.h src/collection_utils/impl/decorators/VectorFactoryLoggerDecorator.h src/generators/GeneratorBuilder.h)
