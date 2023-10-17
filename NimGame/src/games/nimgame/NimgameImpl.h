//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once
#include <vector>
#include "../AbstractGame.h"
#include "../../io/Writer.h"
#include "../player/Player.h"
using namespace games::player;

namespace games::nimgame {

    class NimgameImpl : public AbstractGame<int,int>{

    public:
        explicit NimgameImpl(io::Writer &writer) : AbstractGame(writer) {
            setBoard(23);
        }

    protected:

// --------------------------------- Sumpf --------------------------

        bool isTurnValid() const { return getTurn() >= 1 && getTurn() <= 3; }

        void updateBoard() { setBoard(getBoard() - getTurn()); }

        bool isGameover() const override { // Operation
            return getBoard() <= 0 || getPlayers().empty();
        }

        void prepareTurn() override {
            write(getCurrentPlayer()->getName() + " ist am Zug!");
        }

    };




} // nimgame
