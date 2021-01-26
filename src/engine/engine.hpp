#ifndef __ENGINE_HPP
#define __ENGINE_HPP

#include <string>

class Engine{
    private:
        unsigned short m_winWidth, m_winHeight;
        std::string m_winTitle;

        SDL_Window *m_context;
        SDL_Renderer *m_renderer;
        SDL_Event m_event;

        bool m_alive;

    public:
        Engine();
        Engine(unsigned short width, unsigned short height, std::string title); 
        ~Engine();

        // Main app loop
        void Init();
        void Update();
        void Draw();
        void Quit();

        bool isAlive(){ return m_alive; }

        //Getters && Setters
        unsigned short getWinWidth(){ return m_winWidth; }
        void setWinWidth(unsigned short width){ this->m_winWidth = width; }
        unsigned short getWinHeight(){ return m_winHeight; }
        void setWinHeight(unsigned short height){ this->m_winHeight = height; }
        std::string getWinTitle(){ return m_winTitle; }
        void setWinTitle(std::string title){ this->m_winTitle = title; }
        SDL_Window *getContext(){ return this->m_context; }
        SDL_Renderer *getRenderer(){ return this->m_renderer; }
        SDL_Event getEvent(){ return this->m_event; }
};

#endif