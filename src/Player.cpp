#include "Player.h"

void Player::OnUpdate(float deltaTime) {
  x += m_SpeedX * deltaTime;
  y += m_SpeedY * deltaTime;
}

void Player::HandleEvent(Core::Event& wrappedEvent) {
  SDL_Event event = wrappedEvent.sdlEvent;

  m_SpeedX = 0;
  m_SpeedY = 0;
  if(event.type != SDL_KEYDOWN) {
    return;
  }

  auto keySym = event.key.keysym.sym;
  if(keySym == SDLK_LEFT){
    m_SpeedX = -MOVEMENT_SPEED;
    flipX = true;
  }
  else if(keySym == SDLK_RIGHT){
    m_SpeedX = MOVEMENT_SPEED;
    flipX = false;
  }
  else if(keySym == SDLK_UP){
    m_SpeedY = -MOVEMENT_SPEED;
  }
  else if(keySym == SDLK_DOWN){
    m_SpeedY = MOVEMENT_SPEED;
  }
}

