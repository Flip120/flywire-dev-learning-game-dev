#pragma once

#include "SDL.h"
#include <chrono>
#include "Entity.h"

class Game {
  public:
    Game(int width, int height, const char* title);
    ~Game();
    int init();
    void run();
  private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    int width, height;
    const char* title;
    
    Entity* house;
    Entity* character;
    
    void loadEntities();
    TextureDefinition loadSingleTexture(const char* textureName);
    bool running = false;
    
    void handleEvents();
    void update(float dt);
    void render();
    std::chrono::time_point<std::chrono::high_resolution_clock> m_LastTime;
};
