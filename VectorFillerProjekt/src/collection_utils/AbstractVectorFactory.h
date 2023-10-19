//
// Created by JoachimWagner on 18.10.2023.
//

#pragma once
#include "VectorFactory.h"
namespace collections {


    template<class T>
    class AbstractVectorFactory: public VectorFactory<T>{
        using VECTOR = std::shared_ptr<std::vector<T> >;

        VECTOR data_;
        size_t size_;

    protected:
        auto getData()  -> VECTOR {
            return data_;
        }



        size_t getSize() const {
            return size_;
        }

        virtual auto fill_array() -> void = 0;
    public:
        AbstractVectorFactory() = default;
        ~AbstractVectorFactory() override = default;
        auto createAndFill(size_t size) -> VECTOR override final {

            //data_ = std::unique_ptr<std::vector<T>>{new std::vector<T>(size)};
            data_ = std::make_shared<std::vector<T>>(size);
            size_ = size;
            fill_array();
            return data_;
        }
    };

} // collections
