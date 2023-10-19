//
// Created by JoachimWagner on 19.10.2023.
//

#pragma once
#include <memory>
#include "Generator.h"
namespace generators {

    template<class T>
    class GeneratorBuilder {
    public:
        virtual ~GeneratorBuilder() = default;
        [[nodiscard]] virtual auto create() const->std::unique_ptr<Generator<T>> = 0;
    };

} // generators
