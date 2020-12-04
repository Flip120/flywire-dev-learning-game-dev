#include "Cloud.h"
#include <random>

void Cloud::OnUpdate(float deltaTime){
  if( x > 300)
  {
    x = -100;
    RecalculateMovementSpeed();
  }
  else {
    x += m_MovementSpeed * deltaTime;
  }
}

void Cloud::RecalculateMovementSpeed(){
  m_MovementSpeed = rand() % 5 + 8;
}
