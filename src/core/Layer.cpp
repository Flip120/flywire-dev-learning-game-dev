#include "Layer.h"
#include <algorithm>

Core::Layer::Layer(const std::string& name)
{
  m_DebugName = name;
}

void Core::Layer::SortEntities(){
  std::sort(m_Entities.begin(), m_Entities.end(), SortByVerticalPosition);
}

bool Core::Layer::SortByVerticalPosition(Entity* entity1, Entity* entity2){
  return entity1->y < entity2->y;
}
