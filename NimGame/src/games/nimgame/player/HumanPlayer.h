//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once

#include <iostream>
#include "AbstractNimGamePlayer.h"

namespace games::nimgame::player {
    class HumanPlayer : public AbstractNimGamePlayer {

    public:
        explicit HumanPlayer(const std::string &name) : AbstractNimGamePlayer(name) {}

        int doTurn(const int &stones) const override {
            int turn;
            std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3" << std::endl;
            std::cin >> turn;
            return turn;
        }

    };
}
