cmake_minimum_required(VERSION 3.25)
project(NimGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(NimGame main.cpp src/games/Game.h src/GameClient.h src/games/nimgame/NimgameImpl.h src/games/nimgame/player/AbstractNimGamePlayer.h src/games/nimgame/player/HumanPlayer.h src/games/nimgame/player/ComputerPlayer.h src/io/Writer.h src/io/ConsoleWriter.h src/games/player/Player.h src/games/player/AbstractPlayer.h src/games/AbstractGame.h)
