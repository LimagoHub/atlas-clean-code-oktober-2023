//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once

#include <string>

namespace games::nimgame::player {

    class NimGamePlayer {
    public:

        virtual int doTurn(const int stones) const = 0;
        virtual const std::string &getName() const  = 0;


    };

} // player
