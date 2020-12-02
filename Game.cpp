#include <iostream>
#include <chrono>
#include "SDL.h"
#include "SDL_image.h"
#include "Entity.h"
#include "Game.h"

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

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

  loadEntities();

  return 0;
};

void Game::run(){
  running = true;

  while(running){
    auto now = std::chrono::high_resolution_clock::now();
    float dt = std::chrono::duration<float, std::chrono::seconds::period>(now - m_LastTime).count();
    m_LastTime = now;

    handleEvents();
    update(dt);
    render();

    auto stopTime = std::chrono::high_resolution_clock::now();
  }
}

void Game::handleEvents(){
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      running = false;
      return;
    }
    else{
      character->handleEvent(event);
    }
  }
}
void Game::update(float dt){
  house->update(dt);
  character->update(dt);
}
void Game::render(){
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 60, 150, 99, 255);
  SDL_Rect screenRect = { 0, 0, width, height };
  SDL_RenderDrawRect(renderer, &screenRect);

  house->render(renderer);
  character->render(renderer);

  SDL_RenderPresent(renderer);
}

void Game::loadEntities(){
  TextureDefinition houseTexture = loadSingleTexture("Assets/Images/House.png");
  TextureDefinition charTexture = loadSingleTexture("Assets/Images/Char.png");

  house = new Entity(houseTexture, 0.0f, 0.0f);
  character = new Entity(charTexture,  300.f, 300.0f);
}

TextureDefinition Game::loadSingleTexture(const char* textureName){
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
