//
// Created by JoachimWagner on 18.10.2023.
//

#pragma once
#include <memory>
#include <vector>
namespace collections {

    template<class T>
    class VectorFactory {
        using VECTOR = std::shared_ptr<std::vector<T> >;
    public:

        VectorFactory() = default;
        virtual ~VectorFactory() = default;
        virtual auto createAndFill(size_t size) -> VECTOR = 0;
    };

} // collections
