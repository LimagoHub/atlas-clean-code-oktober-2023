//
// Created by JoachimWagner on 17.10.2023.
//

#pragma once

#include <iostream>
#include "Writer.h"

namespace io {

    class ConsoleWriter : public Writer{
    public:
        void write(std::string message) override {
            std::cout << message << std::endl;
        }
    };

} // io
