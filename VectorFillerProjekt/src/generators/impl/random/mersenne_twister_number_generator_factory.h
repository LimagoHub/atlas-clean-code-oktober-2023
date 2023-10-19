//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once

#include "../../GeneratorBuilder.h"
#include "mersenne_twister_number_generator.h"

namespace generators {
    class mersenne_twister_number_generator_factory : public GeneratorBuilder<int> {
    public:


        ~mersenne_twister_number_generator_factory() override = default;
        [[nodiscard]] auto create() const -> std::unique_ptr<Generator<int>> override
        {
            return std::make_unique<mersenne_twister_number_generator>();
        }
    };
}
