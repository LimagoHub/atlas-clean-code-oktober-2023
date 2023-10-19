//
// Created by JoachimWagner on 18.10.2023.
//

#pragma once
#include <chrono>
namespace mytime {


    class Stopwatch {
    public:
        virtual ~Stopwatch() = default;
        virtual auto start() -> void= 0;
        virtual auto stop()  -> void= 0;

        virtual auto getDuration()->std::chrono::milliseconds = 0;

    };

} // time
