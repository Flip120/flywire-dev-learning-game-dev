#pragma once

#include "Entity.h"
#include "TextureDefinition.hpp"
#include "core/Event.h"
#include "SDL.h"

class Player : public Entity {
  public:
    Player(TextureDefinition textureDefinition, float x, float y)
      : Entity(textureDefinition, x, y){};

    void OnUpdate(float deltaTime) override;
    void HandleEvent(Core::Event& wrappedEvent) override;

  private:
    float m_SpeedX = 0;
    float m_SpeedY = 0;
    const int MOVEMENT_SPEED = 50;
};
