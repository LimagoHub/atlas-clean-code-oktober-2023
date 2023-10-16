//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once


#include <iostream>
#include <memory>
#include "math/Calculator.h"

class Fahrzeug {
public:
    void fahren() {

    }
};

class Client {

    Calculator &calculator;




public:



    explicit Client(Calculator &calculator) : calculator(calculator) {}

    void go() {
       

        std::cout << calculator.add(3,4) << std::endl;
    }

};
