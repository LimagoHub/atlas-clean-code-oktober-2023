//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once
#include <iostream>
#include "Calculator.h"

class CalculatorImpl : public Calculator{




public:
    CalculatorImpl() = default;
     double add(double a, double b) override{
        return a + b;
    }

};
