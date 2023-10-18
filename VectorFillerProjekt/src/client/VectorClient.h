//
// Created by JoachimWagner on 18.10.2023.
//

#pragma once

namespace client {

    class VectorClient {
    public:
        virtual ~VectorClient() = default;
        virtual void doSomethingWithLargeVector() = 0;
    };

} // client
