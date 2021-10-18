#include <iostream>
#include "Game.h"
#include"Player.h"
#include<time.h>

int main()
{
    //Init srand
    std::cout << "Hello im running" << std::endl;
    srand(static_cast<unsigned>(time(NULL)));
    //Init Game Engine
     Game game;
     float deltaTime;
     Clock clock;
    //Game loop
     while (game.running())
     {
         deltaTime = clock.restart().asSeconds();
         //Update
         game.update(deltaTime);
         //Render
         game.render();

     }
     //End of application
    return 0;
}