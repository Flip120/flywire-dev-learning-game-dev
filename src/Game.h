#pragma once

#include <chrono>
#include "SDL.h"
#include "Entity.h"
#include "core/core.h"

class Game {
  public:
    Game(int width, int height, const char* title);
    ~Game();
    int init();

    void PushLayer(Core::Layer* layer);

    TextureDefinition LoadSingleTexture(const char* textureName);
    void run();
  private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    int width, height;
    const char* title;
    
    void loadEntities();
    bool running = false;
    
    void handleEvents();
    void update(float dt);
    void render();
    std::chrono::time_point<std::chrono::high_resolution_clock> m_LastTime;

    Core::LayerStack m_LayerStack;
};
