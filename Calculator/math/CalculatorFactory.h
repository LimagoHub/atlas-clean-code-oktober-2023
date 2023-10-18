//
// Created by JoachimWagner on 18.10.2023.
//

#pragma once
#include <memory>
#include "Calculator.h"
#include "CalculatorImpl.h"
#include "CalculatorLogger.h"
#include "CalculatorSecure.h"

class CalculatorFactory {
        using CALCULATOR = std::unique_ptr<Calculator>;
        inline static bool logger{true};
        inline static bool secure{true};
    public:
    static bool isLogger() {
        return logger;
    }

    static void setLogger(bool logger) {
        CalculatorFactory::logger = logger;
    }

    static bool isSecure() {
        return secure;
    }

    static void setSecure(bool secure) {
        CalculatorFactory::secure = secure;
    }

    static CALCULATOR create() {
            CALCULATOR result = std::make_unique<CalculatorImpl>();

            if(logger)
                result = std::move(std::make_unique<CalculatorLogger>(std::move(result)));

            if(secure)
                result = std::move(std::make_unique<CalculatorSecure>(std::move(result)));

            return result;
        }

    };


