#pragma once
#include <string>
#include "SDL.h"
#include "TextureDefinition.hpp"
#include "core/Event.h"

class Entity {
public:
    Entity(TextureDefinition textureDefiniton, float x, float y);
    ~Entity();
    
    virtual void HandleEvent(Core::Event& event) {};
    virtual void OnUpdate(float deltaTime) {};
    virtual void Render(SDL_Renderer* renderer);

    float x, y;
    TextureDefinition textureDefinition;
protected:
    bool flipX = false;
};
