//
// Created by JoachimWagner on 18.10.2023.
//

#pragma once
#include <memory>
#include <thread>
#include "../generators/impl/random/mersenne_twister_number_generator.h"
#include "../generators/impl/random/mersenne_twister_number_generator_factory.h"
#include "../collection_utils/impl/sequential/VectorFactorySequentialImpl.h"
#include "../collection_utils/impl/parallel/VectorFactoryParallelImpl.h"
#include "../collection_utils/impl/decorators//VectorFactoryBenchmarkDecorator.h"
#include "../collection_utils/impl/decorators//VectorFactoryLoggerDecorator.h"
#include "../client/impl/VectorClientImpl.h"
namespace bootstrap {


    class Bootstrap {

            using VECTOR_FACTORY = std::unique_ptr<collections::VectorFactory<int>>;
            using VECTOR_FACTORY_SEQUENCIAL = collections::VectorFactorySequentialImpl<int>;
            using VECTOR_FACTORY_PARALLEL =  collections::VectorFactoryParallelImpl<int>;
            using VECTOR_FACTORY_BENCHMARK = collections::VectorFactoryBenchmarkDecorator<int>;
            using VECTOR_FACTORY_LOGGER = collections::VectorFactoryLoggerDecorator<int>;


            using GENERATOR_BUILDER = std::unique_ptr<generators::GeneratorBuilder<int>>;


            static auto create(const size_t threadCount = 1) -> void  {

            auto myGeneratorBuilder = createGenerator();

            VECTOR_FACTORY factory = createVectorFactory(std::move(myGeneratorBuilder), threadCount);

            auto client = client::VectorClientImpl{std::move(factory)};
            client.doSomethingWithLargeVector();
        }

        static auto createVectorFactory(GENERATOR_BUILDER myGeneratorBuilder, const size_t threadCount) ->VECTOR_FACTORY {
            VECTOR_FACTORY factory;
            if(threadCount == 1)
                factory = std::make_unique<VECTOR_FACTORY_SEQUENCIAL>(std::move(myGeneratorBuilder->create()));
            else
                factory = std::make_unique<VECTOR_FACTORY_PARALLEL>(std::move(myGeneratorBuilder),threadCount);

            factory = std::make_unique<VECTOR_FACTORY_BENCHMARK>(std::move(factory));
            //factory = std::make_unique<VECTOR_FACTORY_LOGGER>(std::move(factory));
            return factory;
        }


        static auto createGenerator()  -> GENERATOR_BUILDER {
            auto myGenerator = std::unique_ptr<generators::GeneratorBuilder<int>>(
                    std::make_unique<generators::mersenne_twister_number_generator_factory>());
            return myGenerator;
        }


    public:


        auto startApplication()-> void const {
                const size_t availableProcessors = std::thread::hardware_concurrency();
                for (int threadCount = 1; threadCount <= availableProcessors + 1; ++threadCount) {
                    std::cout << "Starte Messung mit " << threadCount << " Threads" << std::endl;
                    create(threadCount);
                }

        }

    };

} // bootstrap
