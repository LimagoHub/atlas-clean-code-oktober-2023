//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once
#include "games/Game.h"
namespace clients {

    using namespace games;

    class GameClient {

        Game &game;

    public:
        explicit GameClient(Game &game) : game(game) {}
        void run() {
            game.play();
        }
    };

} // clients
