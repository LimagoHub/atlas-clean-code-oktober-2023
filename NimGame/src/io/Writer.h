//
// Created by JoachimWagner on 17.10.2023.
//

#pragma once

#include <string>

namespace io {

    class Writer {

    public:
        Writer() = default;
        virtual  ~Writer()= default;

        virtual void write(const std::string &message) const = 0;

    };

} // io
