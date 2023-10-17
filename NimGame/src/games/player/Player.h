//
// Created by JoachimWagner on 17.10.2023.
//

#pragma once
#include <string>
namespace games::player {

    template<class BOARD, class TURN>
    class Player {
    public:
        virtual ~Player(){};
        virtual TURN doTurn(const BOARD board) const = 0;
        virtual const std::string &getName() const  = 0;
    };

} // player
