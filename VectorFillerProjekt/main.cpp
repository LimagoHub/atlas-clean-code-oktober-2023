#include <iostream>
#include <climits>
#include <vector>
#include <cstdlib>
#include <chrono>
#include "src/bootstrap/Bootstrap.h"




auto main() -> int {
    bootstrap::Bootstrap bootstrap;

    bootstrap.startApplication();

    return 0;
}
