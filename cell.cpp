//
//          Klasa opisujaca komorke z dwoma stanami - zywa/ martwa (.cpp)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 29.02.2020
//
//      Modyfikacje:
//          31.03.2020, Szymon Krawczyk - w metodzie setAlive -> return na isAlive()
//

#include "cell.h"

namespace KrawczykS {

    Cell::Cell(bool in_)
        :
        _alive(in_)
    {}

    Cell::Cell(const Cell& in_)
        :
        _alive(in_._alive)
    {}

    Cell::~Cell() {}

    Cell& Cell::operator=(const Cell& in_) {
        
        if (this != &in_) {
            _alive = in_._alive;
        }
        return *this;
    }

    bool Cell::isAlive() const {

        return _alive;
    }

    bool Cell::setAlive(bool in_) {

        _alive = in_;
        return isAlive();
    }
}