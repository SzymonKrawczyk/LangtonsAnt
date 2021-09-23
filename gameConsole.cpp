//
//          Klasa gry Mrowki Langtona obslugujaca konsole (.cpp)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 31.03.2020
//

#include <iostream>
#include "gameConsole.h"

namespace KrawczykS {

    GameConsole::GameConsole(unsigned short width_, unsigned short height_)
        :
        Game(width_, height_)
    {}

    GameConsole::~GameConsole() {}

    void GameConsole::view() const {

        unsigned short tempW = _gameCellStorage.getWidth();
        unsigned short tempH = _gameCellStorage.getHeight();
        system("CLS");

        for (unsigned short height = 0; height < tempH; height++) {
            for (unsigned short width = 0; width < tempW; width++) {

                if (_gameCellStorage.getCellCRef(width, height).isAlive()) {
                    std::cout << 'o';
                }
                else {
                    std::cout << ' ';
                }

                for (int i = 0; i < _antStorage.size(); i++) {

                    if (_antStorage[i]._posX == width && _antStorage[i]._posY == height) {
                        std::cout << '\b' << 'X';
                    }
                }
            }
            std::cout << '\n';
        }
    }

}