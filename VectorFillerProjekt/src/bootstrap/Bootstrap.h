//
// Created by JoachimWagner on 18.10.2023.
//

#pragma once
#include <memory>
#include <thread>
#include "../generators/impl/random/mersenne_twister_number_generator.h"
#include "../collection_utils/impl/sequential/VectorFactorySequentialImpl.h"
#include "../collection_utils/impl/decorators//VectorFactoryBenchmarkDecorator.h"
#include "../collection_utils/impl/decorators//VectorFactoryLoggerDecorator.h"
#include "../client/impl/VectorClientImpl.h"
namespace bootstrap {


    class Bootstrap {

        using VECTOR_FACTORY = std::unique_ptr<collections::VectorFactory<int>>;



        auto create(const size_t threadCount = 1) const -> void  {

            auto myGenerator = createGenerator();

            VECTOR_FACTORY factory = createVectorFactory(std::move(myGenerator));

            auto client = client::VectorClientImpl{std::move(factory)};
            client.doSomethingWithLargeVector();
        }

        auto createVectorFactory(std::unique_ptr<generators::Generator<int>> myGenerator) const->VECTOR_FACTORY {
            VECTOR_FACTORY factory = std::make_unique<collections::VectorFactorySequentialImpl<int>>(std::move(myGenerator));
            factory = std::make_unique<collections::VectorFactoryBenchmarkDecorator<int>>(std::move(factory));
            factory = std::make_unique<collections::VectorFactoryLoggerDecorator<int>>(std::move(factory));
            return factory;
        }


        auto createGenerator() const -> std::unique_ptr<generators::Generator<int>> {
            auto myGenerator = std::unique_ptr<generators::Generator<int>>(new generators::mersenne_twister_number_generator());
            return myGenerator;
        }


    public:


        auto startApplication()-> void {
            for (int threadCount = 1; threadCount <= std::thread::hardware_concurrency() + 1; ++threadCount) {
                create(threadCount);
            }

        }

    };

} // bootstrap
