//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once

#include "NimGamePlayer.h"

namespace games::nimgame::player {

    class AbstractNimGamePlayer: public NimGamePlayer{
    public:
        explicit AbstractNimGamePlayer(const std::string &name) : name(name) {}

        const std::string &getName() const override {
            return name;
        }

    private:
        std::string name;
    };
}
