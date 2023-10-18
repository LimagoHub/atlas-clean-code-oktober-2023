//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once

#include <iostream>
#include "AbstractNimGamePlayer.h"

namespace games::nimgame::player {
    class ComputerPlayer :public AbstractNimGamePlayer{
    private:
        inline static const int ZUEGE[]  {3,1,1,2};

    public:
        explicit ComputerPlayer(const std::string &name) : AbstractNimGamePlayer(name) {}

        int doTurn(const int &stones) const override {

            int turn  = ZUEGE[stones % 4];
            std::cout << "Computer nimmt " << turn << "Steine." << std::endl;
            return turn;
        }
    };
}
