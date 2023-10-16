//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once


#include <iostream>
#include "Calculator.h"

class CalculatorSecure : public Calculator{

    Calculator &calculator;
public:
    explicit CalculatorSecure(Calculator &calculator) : calculator(calculator) {}

    double add(double a, double b) override {
        std::cout << "Du kommst hier rein " << std::endl;

        return calculator.add(a,b);
    }

};
