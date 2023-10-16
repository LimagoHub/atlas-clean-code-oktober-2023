#include <iostream>
#include "math/CalculatorImpl.h"
#include "math/CalculatorLogger.h"
#include "Client.h"
#include "math/CalculatorSecure.h"

int main() {

    CalculatorImpl calc;
    CalculatorLogger logger{calc};
    CalculatorSecure secure{logger};
    Client client {secure};
    client.go();


    return 0;
}
