//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once

#pragma once

#include "Generator.h"

namespace generators {

    class number_generator: public Generator<int> {
    public:
        ~number_generator() override = default;
        [[nodiscard ]] auto next() -> int  override  = 0;
    };
}
