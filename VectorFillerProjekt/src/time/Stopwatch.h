//
// Created by JoachimWagner on 18.10.2023.
//

#pragma once
#include <chrono>
namespace mytime {

    template<class rep>
    class Stopwatch {
    public:
        virtual ~Stopwatch() = default;
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void restart() = 0;
        virtual std::chrono::duration<rep> getDuration();

    };

} // time
