//
//          Klasa opisujaca komorke z dwoma stanami - zywa/ martwa (.h)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 29.02.2020
//
//      Modyfikacje:
//          31.03.2020, Szymon Krawczyk - w metodzie setAlive -> domyslny parametr na true
//

#ifndef CELL_H_
#define CELL_H_

namespace KrawczykS {

    class Cell {

    private:

        bool _alive;

    public:

        Cell(bool = false);
        Cell(const Cell&);
        virtual ~Cell();

        Cell& operator= (const Cell&);

        bool isAlive() const;
        bool setAlive(bool = true);

    };
}
#endif