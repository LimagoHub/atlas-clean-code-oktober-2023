//
// Created by JoachimWagner on 16.10.2023.
//

#pragma once
#include "../Game.h"
namespace games::nimgame {

    class NimgameImpl : public Game{
    public:
        NimgameImpl(): stones{23}, gameover{false} {}

        void play() override {
            while(! isGameover()) {
                playRound();
            }
        }

    private:
        int stones;
        int turn;

        bool gameover;

        void playRound() {// Integration
            playSingleTurn();
            computerTurn();
        }


        void playSingleTurn() { // Integration
            if(isGameover()) return ;

            executeTurn();

            terminateTurn("Human");
        }



        void executeTurn() {
            do {
                humanTurn();
            } while (playersTurnIsInvalid());
        }


        void humanTurn() {
            std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3" << std::endl;
            std::cin >> turn;
        }
        bool playersTurnIsInvalid() {
            if(isTurnValid()) return false ;
            std::cout << "Ungueltiger Zug" << std::endl;
            return true;
        }




        void computerTurn() {
            if(isGameover()) return ;
            const int ZUEGE[] = {3,1,1,2};

            turn  = ZUEGE[stones % 4];
            std::cout << "Computer nimmt " << turn << "Steine." << std::endl;

            terminateTurn( "Computer");
        }

        void terminateTurn( std::string player) { // Integration
            updateBoard();
            printGameOverMessageIfGameIsOver(player);
        }

        void printGameOverMessageIfGameIsOver(const std::string &player) {
            if(isGameover()) {
                std::cout << player << "hat verloren." << std::endl;
            }
        }

// --------------------------------- Sumpf --------------------------

        bool isTurnValid() const { return turn >= 1 && turn <= 3; }

        void updateBoard() { stones -= turn; }

        bool isGameover() { // Operation
            return stones <= 0;
        }

    };




} // nimgame
