#include <iostream>

#include <SDL2/SDL.h> 

#include "engine/engine.hpp"

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

int main(int argc, char *argv[]){
    (void) argc;
    (void) argv;

    Engine GweekEngine(WIN_WIDTH, WIN_HEIGHT, "Gweek Game");

    GweekEngine.Init();

    while(GweekEngine.isAlive()){

        GweekEngine.Update();
        GweekEngine.Draw();

    }

    GweekEngine.Quit();

    return 0;
}