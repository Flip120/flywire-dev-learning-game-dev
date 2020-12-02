#pragma once
#include "SDL.h"
#include "TextureDefinition.hpp"

class Entity {
public:
    Entity(TextureDefinition textureDefiniton, float x, float y);
    ~Entity();
    
    void update(float deltaTime);
    void render(SDL_Renderer* renderer);
    void handleEvent(SDL_Event event);
private:
    TextureDefinition textureDefinition;
    float x,y;
    float speedX, speedY;
};
