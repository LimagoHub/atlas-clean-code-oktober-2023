//
// Created by JoachimWagner on 17.10.2023.
//

#pragma once

#include <string>

namespace io {

    class Writer {

    public:
        virtual  ~Writer(){}

        virtual void write(std::string message) = 0;

    };

} // io
