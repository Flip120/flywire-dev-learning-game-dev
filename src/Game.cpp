#include <iostream>
#include <chrono>
#include "SDL.h"
#include "SDL_image.h"
#include "Entity.h"
#include "Game.h"
#include "core/Event.h"

Game::Game(int width, int height, const char* title){
  this->m_LastTime = std::chrono::high_resolution_clock::now();
  this->width = width;
  this->height = height;
  this->title = title;
  this->running = false;
}

Game::~Game(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int Game::init(){
  SDL_Init(SDL_INIT_VIDEO);
  if (!IMG_Init(IMG_INIT_PNG)) {
    printf("Unable to init SDL_Image, Error:%s\n", IMG_GetError());
    return -1;
  }

  int flags = SDL_WINDOW_OPENGL;
  window = SDL_CreateWindow(
      title,
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      width,
      height,
      flags
      );

  int renderFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
  renderer = SDL_CreateRenderer(window, -1, renderFlags);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  SDL_RenderSetScale(renderer, 6, 6);

  std::cout << "============================" << std::endl;
  std::cout << "Game initiated" << std::endl;

  return 0;
};

void Game::PushLayer(Core::Layer* layer){
  m_LayerStack.PushLayer(layer);
}

void Game::run(){
  running = true;

  while(running){
    auto now = std::chrono::high_resolution_clock::now();
    float dt = std::chrono::duration<float, std::chrono::seconds::period>(now - m_LastTime).count();
    m_LastTime = now;

    handleEvents();
    update(dt);
    render();
  }
}

void Game::handleEvents(){
  SDL_Event sdlEvent;
  while (SDL_PollEvent(&sdlEvent)) {
    if (sdlEvent.type == SDL_QUIT) {
      running = false;
      return;
    }
    else{
      Core::Event event(sdlEvent);
      for(auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it){
        if(event.isHandled()) break;
        (*it)->OnEvent(event);
      }
    }
  }
}

void Game::update(float dt){
  for(Core::Layer* layer : m_LayerStack){
    layer->OnUpdate(dt);
  }
}

void Game::render(){
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 127, 167, 62, 255);
  SDL_Rect screenRect = { 0, 0, width, height };
  SDL_RenderDrawRect(renderer, &screenRect);

  for(auto it = m_LayerStack.begin(); it != m_LayerStack.end(); ++it){
    (*it)->Render(renderer);
  }

  SDL_RenderPresent(renderer);
}

TextureDefinition Game::LoadSingleTexture(const char* textureName){
  SDL_Surface* loadedSurface = IMG_Load(textureName);
  if(loadedSurface == nullptr){
    printf("ERROR, Unable to load %s, Error: %s\n", "", IMG_GetError());
    return TextureDefinition();
  }

  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  if(texture == nullptr)
  {
    printf("ERROR, Unable to load %s, Error: %s\n", "", IMG_GetError());
    return TextureDefinition();
  }

  TextureDefinition textureDefinition = { texture, loadedSurface->w, loadedSurface->h };

  SDL_FreeSurface(loadedSurface);
  return textureDefinition;
}
