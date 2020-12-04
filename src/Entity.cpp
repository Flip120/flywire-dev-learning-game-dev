#include "Entity.h"
#include "SDL.h"
#include <iostream>

Entity::Entity(TextureDefinition textureDefinition, float x, float y){
    this->textureDefinition = textureDefinition;
    this->x = x;
    this->y = y;
}

Entity::~Entity(){
    SDL_DestroyTexture(textureDefinition.texture);
}

void Entity::Render(SDL_Renderer *renderer){
    SDL_Rect srcRect {
        0,
        0,
        textureDefinition.width,
        textureDefinition.height
    };
    
    SDL_Rect dstRect {
        (int)x,
        (int)y,
        textureDefinition.width,
        textureDefinition.height
    };

    SDL_Point center = { (int) (textureDefinition.width * 0.5f), (int) (textureDefinition.height * 0.5f) };
    SDL_RendererFlip flip = flipX ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

    SDL_RenderCopyEx(renderer, textureDefinition.texture, &srcRect, &dstRect, 0, &center, flip);
}
