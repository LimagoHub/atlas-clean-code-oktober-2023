//
// Created by JoachimWagner on 17.10.2023.
//

#pragma once
#include "Player.h"
namespace games::player {

    template<class BOARD, class TURN>
    class AbstractPlayer: public Player<BOARD,TURN>{
    public:
        explicit AbstractPlayer(const std::string &name) : name(name) {}
        virtual ~AbstractPlayer(){}
    private:
        const std::string &getName() const override {
            return name;
        }

    private:
        std::string name;
    };
} // player
