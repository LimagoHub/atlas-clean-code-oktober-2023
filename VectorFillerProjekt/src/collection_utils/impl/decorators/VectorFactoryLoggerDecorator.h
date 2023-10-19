//
// Created by JoachimWagner on 19.10.2023.
//

#pragma once

#include <iostream>
#include "AbstractVectorFactoryDecorator.h"
namespace collections {

    template<class T>
    class VectorFactoryLoggerDecorator: public AbstractVectorFactoryDecorator<T>{
        using VectorFactoryPointer = std::unique_ptr<VectorFactory<T>>;
        using VECTOR = std::shared_ptr<std::vector<T>>;
    public:
        explicit VectorFactoryLoggerDecorator(VectorFactoryPointer vectorFactoryPointer)
                : AbstractVectorFactoryDecorator<T>(std::move(vectorFactoryPointer)) {}

        auto createAndFill(size_t size) -> VECTOR override {
            std::cout << "createAndFill wurde mit size " << size << "aufgerufen!" << std::endl;
            return this->vectorFactoryPointer->createAndFill(size);
        }
    };

} // collections
