//
// Created by JoachimWagner on 19.10.2023.
//

#pragma once
#include <memory>
#include "../../VectorFactory.h"
namespace collections {
    template<class T>
    class AbstractVectorFactoryDecorator : public VectorFactory<T> {

        using VectorFactoryPointer = std::unique_ptr<VectorFactory<T>>;
    protected:

        VectorFactoryPointer vectorFactoryPointer;

    public:
        virtual ~AbstractVectorFactoryDecorator() = default;

        AbstractVectorFactoryDecorator(VectorFactoryPointer vectorFactoryPointer)
                : vectorFactoryPointer(std::move(vectorFactoryPointer)) {}

    };
}