#include <iostream>
#include "src/games/nimgame/NimgameImpl.h"
#include "src/games/nimgame/player/ComputerPlayer.h"
#include "src/games/nimgame/player/HumanPlayer.h"
#include "src/io/ConsoleWriter.h"
#include "src/GameClient.h"

using namespace games::nimgame::player;

int main() {

    io::ConsoleWriter writer;
    HumanPlayer fritz{"Fritz"};
    ComputerPlayer hal{"HAL"};
    games::nimgame::NimgameImpl game{writer};
    game.addPlayer(&fritz);
    game.addPlayer(&hal);
    clients::GameClient client {game};
    client.run();
    return 0;
}
