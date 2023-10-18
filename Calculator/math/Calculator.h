//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once


class Calculator {

public:
    virtual ~Calculator() = default;
    Calculator() = default;
    virtual double add(double a, double b) = 0;

};
