#include <stdio.h>
#include <iostream>
#include "SDL.h"
#include "src/Game.h"
#include "src/core/core.h"
#include "src/Entity.h"
#include "src/Player.h"

int main(void) {
    Game* game = new Game(800, 600, "Dev learnings game");
    
    int exitCode = game->init();

    Core::Layer* buildingsLayer = new Core::Layer("Buildings");
    Core::Layer* charactersLayer = new Core::Layer("Characters");

    TextureDefinition houseTexture = game->LoadSingleTexture("Assets/Images/House.png");
    TextureDefinition idleTexture = game->LoadSingleTexture("Assets/Images/Idle.png");
    Entity* house = new Entity(houseTexture, 0.0f, 0.0f);
    Player* player = new Player(idleTexture, 300.f, 300.0f);

    buildingsLayer->PushEntity(house);
    charactersLayer->PushEntity(player);

    game->PushLayer(buildingsLayer);
    game->PushLayer(charactersLayer);
    game->run();
        
    delete game;
    return exitCode;
}
