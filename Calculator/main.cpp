#include <iostream>
#include "math/CalculatorFactory.h"

#include "Client.h"


int main() {

    CalculatorFactory::setLogger(true);
    CalculatorFactory::setSecure(false);
    auto calc = CalculatorFactory::create();
    Client client {std::move(calc)};
    client.go();


    return 0;
}
