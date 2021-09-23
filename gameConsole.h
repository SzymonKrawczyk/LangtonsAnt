//
//          Klasa gry Mrowki Langtona obslugujaca konsole (.h)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 31.03.2020
//

#ifndef GAMECONSOLE_H_
#define GAMECONSOLE_H_

#include "game.h"

namespace KrawczykS {

    class GameConsole : public Game {
    public:

        GameConsole(unsigned short = 0, unsigned short = 0);
        GameConsole(const GameConsole&) = delete;
        GameConsole& operator=(const GameConsole&) = delete;
        virtual ~GameConsole();

        virtual void view() const;
    };
}

#endif