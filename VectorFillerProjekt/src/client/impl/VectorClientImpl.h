//
// Created by JoachimWagner on 18.10.2023.
//

#pragma once

#include <iostream>
#include <climits>
#include "../../collection_utils/VectorFactory.h"

#include "../VectorClient.h"

namespace client {

    class VectorClientImpl: public VectorClient {
        using VECTOR = std::unique_ptr<collections::VectorFactory<int> >;

        VECTOR factory;


    public:

        explicit VectorClientImpl(VECTOR factory) : factory(std::move(factory)) {}

        ~VectorClientImpl() override = default;

        auto doSomethingWithLargeVector() ->void  override{
            auto v = factory->createAndFill(INT_MAX/8);
            for (int i = 0; i < 3; ++i) {
                //std::cout << v->at(i) << std::endl;
            }
        }
    };

} // client
