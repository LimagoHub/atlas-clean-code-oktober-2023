//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once

#include "../../player/AbstractPlayer.h"

namespace games::nimgame::player {
    using namespace games::player;

    class AbstractNimGamePlayer : public AbstractPlayer<int, int> {
    public:
        AbstractNimGamePlayer(const std::string &name) : AbstractPlayer(name) {}

        virtual ~AbstractNimGamePlayer() override {}


    };
}