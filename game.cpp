#include "game.h"

namespace KrawczykS {

    // Klasa Mrowki

        Game::Ant::Ant(short inX_, short inY_, Direction d_)
            :
                _posX(inX_)
            ,   _posY(inY_)
            ,   _direction(d_)
        {}

        Game::Ant::Ant(const Ant& in_)
            :
                _posX(in_._posX)
            ,   _posY(in_._posY)
            ,   _direction(in_._direction)
        {}

        Game::Ant::~Ant() {}

        Game::Ant& Game::Ant::operator=(const Ant& in_) {

            if (this != &in_) {

                _posX = in_._posX;
                _posY = in_._posY;
                _direction = in_._direction;
            }
            return *this;
        }

        void Game::Ant::feed(Cell& food_) {

            if (food_.isAlive()) {

                food_.setAlive(false);

                switch (_direction) {
                    case N: _direction = W; break;
                    case E: _direction = N; break;
                    case W: _direction = S; break;
                    case S: _direction = E; break;
                }
            }
            else {

                food_.setAlive();

                switch (_direction) {
                    case N: _direction = E; break;
                    case E: _direction = S; break;
                    case W: _direction = N; break;
                    case S: _direction = W; break;
                }
            }
        }

        void Game::Ant::move() {

            switch (_direction) {
                case N: --_posY; break;
                case E: ++_posX; break;
                case W: --_posX; break;
                case S: ++_posY; break;
            }
        }
    //

    // Klasa Gry

        Game::Game(unsigned short w_, unsigned short h_)
            :
                _gameCellStorage(w_, h_)
            ,   _antStorage()
        {}

        Game::~Game() {}

        void Game::addAnt(short posX_, short posY_, int dir_) {

            dir_ %= 4;  // Aby na pewno pozostac w zakresie enumeratora

            Ant temp(posX_, posY_, (Ant::Direction)dir_);

            _antStorage.push_back(temp);    // Wykonuje sie kopia temp
        }

        void Game::checkBoundaries(Ant& in_) {

                 if (in_._posX > _gameCellStorage.getWidth() - 1) {
                in_._posX = 0;
            }
            else if (in_._posX < 0) {
                in_._posX = _gameCellStorage.getWidth() - 1;
            }

                 if (in_._posY > _gameCellStorage.getHeight() - 1) {
                in_._posY = 0;
            }
            else if (in_._posY < 0) {
                in_._posY = _gameCellStorage.getHeight() - 1;
            }
        }

        void Game::analyse() {

            for (int i = 0; i < _antStorage.size(); i++) {

                checkBoundaries(_antStorage[i]);
                _antStorage[i].feed(_gameCellStorage.getCellRef(_antStorage[i]._posX, _antStorage[i]._posY));
                _antStorage[i].move();
            }
        }

        void KrawczykS::Game::play() {

            analyse();
            view();
        }
    //
}