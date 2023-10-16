//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once


#include "Calculator.h"

class CalculatorLogger : public Calculator{

    Calculator &calculator;
public:
    CalculatorLogger(Calculator &calculator) : calculator(calculator) {}
    double add(double a, double b) {
        std::cout << "Add wurde gerufen" << std::endl;
        return calculator.add(a,b);
    }
};




