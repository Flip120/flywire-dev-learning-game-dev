#pragma once
#include "SDL.h"
#include "TextureDefinition.hpp"
#include "core/Event.h"

class Entity {
public:
    Entity(TextureDefinition textureDefiniton, float x, float y);
    ~Entity();
    
    virtual void OnUpdate(float deltaTime) {};
    virtual void HandleEvent(Core::Event& event) {};
    virtual void Render(SDL_Renderer* renderer);

protected:
    TextureDefinition textureDefinition;
    float x, y;
    bool flipX = false;
};
