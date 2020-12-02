#include "Entity.h"
#include "SDL.h"
#include <iostream>

Entity::Entity(TextureDefinition textureDefinition, float x, float y){
    this->textureDefinition = textureDefinition;
    this->x = x;
    this->y = y;
    this->speedX = 0.0f;
    this->speedY = 0.0f;
}

Entity::~Entity(){
    SDL_DestroyTexture(textureDefinition.texture);
}

void Entity::handleEvent(SDL_Event event){
    if(event.type != SDL_KEYDOWN) return;
    
    auto keySym = event.key.keysym.sym;
    if(keySym == SDLK_LEFT){
        speedX = -1;
    }
    else if(keySym == SDLK_RIGHT){
        speedX = 1;
    }
    else if(keySym == SDLK_UP){
        speedY = -1;
    }
    else if(keySym == SDLK_DOWN){
        speedY = 1;
    }
}

void Entity::update(float deltaTime){
    x += speedX * deltaTime;
    y += speedY * deltaTime;
}

void Entity::render(SDL_Renderer *renderer){
    SDL_Rect srcRect {
        0,
        0,
        textureDefinition.width,
        textureDefinition.height
    };
    
    /* std::cout << this->x << ", " << this->y << std::endl; */
    SDL_Rect dstRect {
        (int)x,
        (int)y,
        textureDefinition.width * 4,
        textureDefinition.height * 4
    };
    
    SDL_RenderCopy(renderer, textureDefinition.texture, &srcRect, &dstRect);
}
