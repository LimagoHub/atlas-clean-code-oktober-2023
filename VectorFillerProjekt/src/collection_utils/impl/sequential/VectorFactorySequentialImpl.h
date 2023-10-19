//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once
#include <memory>
#include "../../AbstractVectorFactory.h"
#include "../../../generators/generator.h"

namespace collections {

    template<class T>
    class VectorFactorySequentialImpl : public AbstractVectorFactory<T>{
        using VECTOR = std::unique_ptr<std::vector<T> >;

        using MyGenerator =  std::unique_ptr<generators::Generator<T>>;
        MyGenerator generator_;


    public:

        explicit VectorFactorySequentialImpl(MyGenerator generator) : generator_(std::move(generator)) {}
        VectorFactorySequentialImpl() = default;
        ~VectorFactorySequentialImpl()  override = default;



    protected:
        auto fill_array() -> void override {
            auto field = this->getData();
            for (size_t i = 0; i < this->getSize(); ++i) {
                field->at(i) = generator_->next();
            }
        }

    };

}
