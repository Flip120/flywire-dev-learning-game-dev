#pragma once

#include <string>
#include <vector>
#include "SDL.h"
#include "Event.h"
#include "../Entity.h"

namespace Core {
  class Layer
  {
    public:
      Layer(const std::string& name = "Layer");
      virtual ~Layer() = default;

      virtual void OnAttach() {};

      virtual void OnDetach() {
        for(Entity* entity : m_Entities) {
          delete entity;
        }
      };

      virtual void OnEvent(Core::Event& event) {
        for(Entity* entity : m_Entities) {
          entity->HandleEvent(event);
        }
      };

      virtual void OnUpdate(float dt) {
        for(Entity* entity : m_Entities) {
          entity->OnUpdate(dt);
        }
      };

      virtual void Render(SDL_Renderer* renderer){
        for(Entity* entity : m_Entities) {
          entity->Render(renderer);
        }
      }
      
      virtual void PushEntity(Entity* entity) { m_Entities.emplace_back(entity); }

      const std::string& GetName() { return m_DebugName; }

    private:
      std::vector<Entity*> m_Entities;
      std::string m_DebugName;
  };
}
