//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once


#include <iostream>
#include <memory>
#include "math/Calculator.h"


class Client {

    using CALCULATOR = std::unique_ptr<Calculator>;
    CALCULATOR calculator_;




public:


    explicit Client(CALCULATOR calculator) : calculator_(std::move(calculator)) {}

    void go() {


        std::cout << calculator_->add(3,4) << std::endl;
    }

};
