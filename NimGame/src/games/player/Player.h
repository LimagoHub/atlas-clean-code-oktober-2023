//
// Created by JoachimWagner on 17.10.2023.
//

#pragma once
#include <string>
namespace games::player {

    template<class BOARD, class TURN>
    class Player {
    public:
        Player() = default;
        virtual ~Player()= default;
        virtual TURN doTurn(const BOARD &board) const = 0;
        [[nodiscard]] virtual const std::string &getName() const  = 0;
    };

} // player
