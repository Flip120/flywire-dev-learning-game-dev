#pragma once

#include "SDL.h"

namespace Core {
  class Event {
    public:
      Event(SDL_Event& event) : sdlEvent(event){};

      SDL_Event& sdlEvent;
      bool isHandled() { return m_Handled; }
    private:
      bool m_Handled = false;
  };
}
