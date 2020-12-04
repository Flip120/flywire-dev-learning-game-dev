#pragma once

#include "Entity.h"

class Cloud : public Entity{
public:
  Cloud(TextureDefinition textureDefinition, float x, float y)
    : Entity(textureDefinition, x, y){
      RecalculateMovementSpeed();
    };

  void OnUpdate(float deltaTime) override;

private:
  int m_MovementSpeed = 5.0f;
  void RecalculateMovementSpeed();
};
