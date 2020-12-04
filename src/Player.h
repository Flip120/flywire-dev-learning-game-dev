#pragma once

#include "Entity.h"
#include "TextureDefinition.hpp"
#include "core/Event.h"
#include "SDL.h"

class Player : public Entity {
  public:
    Player(TextureDefinition textureDefinition, float x, float y)
      : Entity(textureDefinition, x, y){};

    void HandleEvent(Core::Event& wrappedEvent) override;
    void OnUpdate(float deltaTime) override;

  private:
    float m_SpeedX = 0;
    float m_SpeedY = 0;
    const float MOVEMENT_SPEED = 30;
};
