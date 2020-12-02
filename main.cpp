#include <stdio.h>
#include <iostream>
#include "SDL.h"
#include "Game.h"
#include "Entity.h"

int main(void) {
    Game* game = new Game(800, 600, "Dev learnings game");
    
    int exitCode = game->init();
    game->run();
        
    delete game;
    return exitCode;
}
