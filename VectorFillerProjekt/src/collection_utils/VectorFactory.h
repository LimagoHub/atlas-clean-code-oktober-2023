//
// Created by JoachimWagner on 18.10.2023.
//

#pragma once
#include <memory>
#include <vector>
namespace collections {

    template<class T>
    class VectorFactory {
        using VECTOR = std::unique_ptr<std::vector<T> >;
    public:
        VectorFactory() = default;
        virtual ~VectorFactory() = default;
        virtual VECTOR createAndFill(size_t size) = 0;
    };

} // collections
