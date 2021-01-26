#include <iostream>

#include <SDL2/SDL.h>

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
    //TODO
}

void Engine::Draw(){
    SDL_RenderClear(getRenderer());

    SDL_Rect rect;
    rect.x = 250;
    rect.y = 150;
    rect.w = 200;
    rect.h = 200;

    SDL_SetRenderDrawColor(getRenderer(), 255, 255, 255, 255);
    SDL_RenderDrawRect(getRenderer(), &rect);

    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255);

    SDL_RenderPresent(getRenderer());
}

void Engine::Quit(){
    SDL_Quit();
}