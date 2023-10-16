#include <iostream>
#include "src/games/nimgame/NimgameImpl.h"
#include "src/GameClient.h"


int main() {

    games::nimgame::NimgameImpl game;
    clients::GameClient client {game};
    client.run();
    return 0;
}
