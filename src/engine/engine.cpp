#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "engine.hpp"

Engine::Engine(){
    Engine(800, 600, "DEFAULT_TITLE");
}

Engine::Engine(unsigned short width, unsigned short height, std::string title){
    setWinWidth(width);
    setWinHeight(height);
    setWinTitle(title);
    this->m_alive = false;
}

Engine::~Engine(){}

void Engine::Init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "ERROR::Initializing SDL - " << SDL_GetError() << std::endl;
    }

    this->m_context = SDL_CreateWindow(getWinTitle().c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, getWinWidth(), getWinHeight(), 0);
    this->m_renderer = SDL_CreateRenderer(m_context, -1, 0);

    if(this->m_context != NULL)
        this->m_alive = true;
}

void Engine::Update(){
    SDL_Event e = getEvent();

    while(SDL_PollEvent(&e) > 0){
        switch(e.type){
            case SDL_QUIT:
                this->m_alive = false;
                break;
        }
    }
}

void Engine::Draw(){
    SDL_RenderClear(getRenderer());

    SDL_Texture *img = NULL;
    int w,h;
    img = IMG_LoadTexture(getRenderer(), "data/sprites/issou.png");

    SDL_QueryTexture(img, NULL, NULL, &w, &h);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = w;
    rect.h = h;
    SDL_RenderCopy(getRenderer(), img, NULL, &rect);

    SDL_RenderPresent(getRenderer());
}

void Engine::Quit(){
    SDL_Quit();
}