//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once


#include "Calculator.h"
#include <memory>
class CalculatorLogger : public Calculator{
    using CALCULATOR = std::unique_ptr<Calculator>;
    CALCULATOR calculator_;
public:
    CalculatorLogger(CALCULATOR calculator) : calculator_(std::move(calculator)) {}

    double add(double a, double b) {
        std::cout << "Add wurde gerufen" << std::endl;
        return calculator_->add(a,b);
    }
};




