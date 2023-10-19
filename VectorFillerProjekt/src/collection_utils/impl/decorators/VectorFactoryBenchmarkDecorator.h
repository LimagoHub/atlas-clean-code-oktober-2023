//
// Created by JoachimWagner on 19.10.2023.
//

#pragma once

#include <iostream>
#include "AbstractVectorFactoryDecorator.h"
#include "../../../time/StopwatchImpl.h"
namespace collections {

    template<class T>
    class VectorFactoryBenchmarkDecorator: public AbstractVectorFactoryDecorator<T> {
        using VectorFactoryPointer = std::unique_ptr<VectorFactory<T>>;
        using StopwatchPointer = std::unique_ptr<mytime::Stopwatch>;
        using VECTOR = std::shared_ptr<std::vector<T>>;

        StopwatchPointer stopwatch_;
    public:
        //~VectorFactoryBenchmarkDecorator() override= default;
        explicit VectorFactoryBenchmarkDecorator(VectorFactoryPointer vectorFactoryPointer_,
            StopwatchPointer stopwatch=std::make_unique<mytime::StopwatchImpl>())
            :AbstractVectorFactoryDecorator<T>{std::move(vectorFactoryPointer_)},stopwatch_{std::move(stopwatch)}{}


        auto createAndFill(size_t size) -> VECTOR override {
            stopwatch_->start();
            VECTOR result = this->vectorFactoryPointer->createAndFill(size);
            stopwatch_->stop();
            std::cout << "Dauer = " << stopwatch_->getDuration().count() << " millis." << std::endl;
            return result;
        }

    };

} // collections
