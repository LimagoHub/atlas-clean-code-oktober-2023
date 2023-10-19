//
// Created by JoachimWagner on 19.10.2023.
//

#pragma once
#include <vector>
#include <thread>
#include <cmath>
#include "../../../generators/GeneratorBuilder.h"
#include "../../AbstractVectorFactory.h"
namespace collections {

    template<class T>
    class VectorFactoryAutoImpl :public AbstractVectorFactory<T>{

    protected:
        auto fill_array() -> void override {
//            auto generator = generatorFactory_->create();
//            std::for_each(std::execution::par, this->getData()->begin(), this->getData()->end(),[&generator](T &value){
//                value = generator->next();
//            }
    };


}

} // collections
