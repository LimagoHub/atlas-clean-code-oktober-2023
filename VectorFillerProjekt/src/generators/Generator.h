//
// Created by JoachimWagner on 18.10.2023.
//

#pragma once

namespace generators {

    template<class T>
    class Generator {
    public:
        virtual ~Generator() = default;
        virtual auto next() -> T = 0;

    };

} // generators
