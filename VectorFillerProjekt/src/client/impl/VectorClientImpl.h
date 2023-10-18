//
// Created by JoachimWagner on 18.10.2023.
//

#pragma once

#include <iostream>
#include "../../collection_utils/VectorFactory.h"

#include "../VectorClient.h"

namespace client {

    class VectorClientImpl: public VectorClient {
        using VECTOR = std::unique_ptr<std::vector<int> >;

        collections::VectorFactory<int> &factory;


    public:

        explicit VectorClientImpl(collections::VectorFactory<int> &factory) : factory(factory) {}

        ~VectorClientImpl() override = default;

        void doSomethingWithLargeVector() override {
            VECTOR v = factory.createAndFill(10);
            for (int i = 0; i < 3; ++i) {
                std::cout << v->at(i) << std::endl;
            }
        }
    };

} // client
