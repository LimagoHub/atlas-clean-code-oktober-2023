//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once


#include <iostream>
#include "Calculator.h"

class CalculatorSecure : public Calculator{

    using CALCULATOR = std::unique_ptr<Calculator>;
    CALCULATOR calculator_;
public:
    CalculatorSecure(CALCULATOR calculator) : calculator_(std::move(calculator)) {}

    double add(double a, double b) override {
        std::cout << "Du kommst hier rein " << std::endl;

        return calculator_->add(a,b);
    }

};
