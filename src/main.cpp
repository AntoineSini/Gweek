#include <iostream>

#include <SDL2/SDL.h> 

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

int main(int argc, char *argv[]){
    (void) argc;
    (void) argv;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "ERROR::Initializing SDL - " << SDL_GetError() << std::endl;
    }

    SDL_Window *win = SDL_CreateWindow("Gweek Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, 0);
    (void) win;

    while(1);

    return 0;
}