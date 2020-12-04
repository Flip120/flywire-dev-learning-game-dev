#include <stdio.h>
#include <iostream>
#include "SDL.h"
#include "src/Game.h"
#include "src/core/core.h"
#include "src/Entity.h"
#include "src/Cloud.h"
#include "src/Player.h"

int main(void) {
    Game* game = new Game(1600, 900, "Dev learnings game");
    int exitCode = game->init();

    Core::Layer* buildingsLayer = new Core::Layer("Buildings");
    Core::Layer* charactersLayer = new Core::Layer("Characters");
    Core::Layer* roadsLayer = new Core::Layer("Roads");
    Core::Layer* groundLayer = new Core::Layer("Ground");
    Core::Layer* treesLayer = new Core::Layer("Trees");
    Core::Layer* skyLayer = new Core::Layer("Sky");

    TextureDefinition roadsTexture = game->LoadSingleTexture("Assets/Images/layer-roads.png");
    Entity* roads = new Entity(roadsTexture, 21.0f, 15.0f);
    roadsLayer->PushEntity(roads);

    TextureDefinition fieldTexture = game->LoadSingleTexture("Assets/Images/Field.png");
    Entity* field1 = new Entity(fieldTexture, 100.0f, 10.0f);
    Entity* field2 = new Entity(fieldTexture, 132.0f, 10.0f);
    Entity* field3 = new Entity(fieldTexture, 100.0f, 42.0f);
    Entity* field4 = new Entity(fieldTexture, 132.0f, 42.0f);
    groundLayer->PushEntity(field1);
    groundLayer->PushEntity(field2);
    groundLayer->PushEntity(field3);
    groundLayer->PushEntity(field4);

    TextureDefinition houseTexture = game->LoadSingleTexture("Assets/Images/Buildings.png");
    Entity* house = new Entity(houseTexture, 0.0f, 0.0f);
    buildingsLayer->PushEntity(house);

    TextureDefinition soldier1Texture = game->LoadSingleTexture("Assets/Images/Soldier1.png");
    Entity* soldier1 = new Entity(soldier1Texture, 5.0f, 18.0f);
    charactersLayer->PushEntity(soldier1);

    TextureDefinition idleTexture = game->LoadSingleTexture("Assets/Images/Idle.png");
    Player* player = new Player(idleTexture, 100.f, 100.0f);
    TextureDefinition womanTexture = game->LoadSingleTexture("Assets/Images/Woman.png");
    Entity* woman = new Entity(womanTexture, 40.0f, 60.0f);
    charactersLayer->PushEntity(player);
    charactersLayer->PushEntity(woman);

    TextureDefinition treesTexture = game->LoadSingleTexture("Assets/Images/Trees.png");
    Entity* trees = new Entity(treesTexture, 100.0f, 65.0f);
    treesLayer->PushEntity(trees);
    
    TextureDefinition cloudTexture = game->LoadSingleTexture("Assets/Images/Cloud1.png");
    TextureDefinition cloudTexture2 = game->LoadSingleTexture("Assets/Images/Cloud2.png");
    Cloud* cloud1 = new Cloud(cloudTexture, 120.0f, 30.0f);
    Cloud* cloud2 = new Cloud(cloudTexture, 10.0f, 100.0f);
    Cloud* cloud3 = new Cloud(cloudTexture, -120.0f, 80.0f);
    skyLayer->PushEntity(cloud1);
    skyLayer->PushEntity(cloud2);
    skyLayer->PushEntity(cloud3);

    game->PushLayer(roadsLayer);
    game->PushLayer(groundLayer);
    game->PushLayer(buildingsLayer);
    game->PushLayer(charactersLayer);
    game->PushLayer(treesLayer);
    game->PushLayer(skyLayer);
    game->run();
        
    delete game;
    return exitCode;
}
