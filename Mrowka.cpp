/*

    Program uruchamiajacy Mrowke Langtona
    
    Autor implementacji: Szymon Krawczyk

    Data utworzenia: 31.03.2020

*/

#include <Windows.h>
#include <fstream>
#include <iostream>

#include "gameConsole.h"

int main() {

    try {

        std::ifstream fileIn;
        fileIn.open("gameData.ini");

        if (!fileIn.is_open()) throw "Blad otwarcia pliku \"gameData.ini\"";

        KrawczykS::Game* game = nullptr;
        short CPS = 1;

        short tempGM = 0, tempW = 0, tempH = 0;
        if (fileIn >> tempGM >> CPS >> tempW >> tempH) {

            switch (tempGM) {

                case 1: game = new KrawczykS::GameConsole(tempW, tempH); break;
            }
        }
        else {

            throw "Nieoczekiwany koniec pliku \"gameData.ini\"";
        }

        unsigned short tempX, tempY, tempD;
        while (fileIn >> tempX >> tempY >> tempD) {

            game->addAnt(tempX, tempY, tempD);
        }


        while (true) {

            game->play();
            std::cin.get(); // Odkomentowanie i zakomentowanie sleep = sterowanie ruchem za pomoca entera
            //Sleep(1000/CPS);
        }

    } 
    catch (const char* err) {

        std::clog << '\n' << err << '\n';
        std::cin.get();
        exit(EXIT_FAILURE);
    }
    return 0;
}