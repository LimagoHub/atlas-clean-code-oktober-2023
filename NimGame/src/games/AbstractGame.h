//
// Created by JoachimWagner on 17.10.2023.
//

#pragma once
#include <vector>
#include "Game.h"
#include "../io/Writer.h"
#include "player/Player.h"
namespace games {

    template<class BOARD, class TURN>
    class AbstractGame: public Game {
        using PLAYER = games::player::Player<BOARD, TURN> *;
    public:
        explicit AbstractGame(io::Writer &writer) : writer(writer) {}


        void addPlayer(PLAYER player) {
            players.push_back(player);
        }

        /*
         * see Game.play()
         *
         */
        void play() override {
            while(! isGameover()) {
                playRound();
            }
        }



    private:
        BOARD board;
        TURN turn;
        io::Writer &writer;

        std::vector<PLAYER> players;
        PLAYER currentPlayer;

        void playRound() {// Integration

            for( auto player: players){
                setCurrentPlayer(player);
                playSingleTurn();
            }


        }

        void playSingleTurn() { // Integration
            if(isGameover()) return ;
            prepareTurn();
            executeTurn();

            terminateTurn();
        }

        void executeTurn() {
            do {
                turn = getCurrentPlayer()->doTurn(board);
            } while (playersTurnIsInvalid());
        }

        void terminateTurn( ) { // Integration
            updateBoard();
            printGameOverMessageIfGameIsOver();
        }
        bool playersTurnIsInvalid() {
            if(isTurnValid()) return false ;

            write("Ungueltiger Zug");
            return true;
        }

        void printGameOverMessageIfGameIsOver() {
            if(isGameover()) {
                write( getCurrentPlayer()->getName() + " hat verloren.");
            }
        }

        void setCurrentPlayer(const PLAYER currentPlayer) {
            AbstractGame::currentPlayer = currentPlayer;
        }

    protected:
        BOARD getBoard() const {
            return board;
        }

        void setBoard(BOARD board) {

            AbstractGame::board = board;
        }

        TURN getTurn() const {

            return turn;
        }

        void setTurn(TURN turn) {
            AbstractGame::turn = turn;
        }

        void write(std::string message){
            writer.write(message);
        }

        // ---- Sumpf ---
        virtual bool isGameover() const = 0;
        virtual void updateBoard() = 0;
        virtual bool isTurnValid() const = 0;
        virtual void prepareTurn() {
            // NOP
        }
        // -- Sumpf ende ---

        const player::Player<BOARD, TURN> *getCurrentPlayer() const {
            return currentPlayer;
        }

        const std::vector<PLAYER> &getPlayers() const {
            return players;
        }




    };



}
