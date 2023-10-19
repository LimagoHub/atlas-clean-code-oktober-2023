//
// Created by JoachimWagner on 18.10.2023.
//

#pragma once
#include "Stopwatch.h"
#include <stdexcept>
namespace mytime {

    class StopwatchImpl: public Stopwatch {

        std::chrono::high_resolution_clock::time_point start_;
        std::chrono::high_resolution_clock::time_point end_;
    public:
        StopwatchImpl()=default;

        ~StopwatchImpl() override {

        }


        auto start() -> void override {
            start_ = std::chrono::high_resolution_clock::now();
        }

        auto stop() -> void override {
            end_ = std::chrono::high_resolution_clock::now();
        }



        auto getDuration() -> std::chrono::milliseconds override {
            return std::chrono::duration_cast<std::chrono::milliseconds>(end_-start_);
        }
    };

} // mytime
