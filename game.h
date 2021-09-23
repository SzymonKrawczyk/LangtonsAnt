//
//          Klasa gry Mrowki Langtona (.h)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 31.03.2020
//

#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "cellArray.h"

namespace KrawczykS {

    class Game {

    private:

        class Ant {

            public:

                enum Direction {

                    N = 0, E, W, S
                };

                short _posX;
                short _posY;
                Direction _direction;

                Ant(short = 0, short = 0, Direction = W);
                Ant(const Ant&);
                Ant& operator= (const Ant&);
                virtual ~Ant();

                void feed(Cell&);
                void move();

        };

    protected:

        CellArray _gameCellStorage;
        std::vector<Ant> _antStorage;

        void checkBoundaries(Ant&);

    public:

        Game(unsigned short = 10, unsigned short = 10);
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
        virtual ~Game();

        void addAnt(short = 0, short = 0, int = 2);   // W cpp rzutowanie z int na enum

        void analyse();
        void play();

        virtual void view() const = 0;

    };
}

#endif