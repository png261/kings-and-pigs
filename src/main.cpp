#include <iostream>
#include "Game.h"
#include "Timer.h"

const unsigned int FPS = 60;
const unsigned int DELAY_TIME = 1000.f / FPS;

int main(int argc, char* argv[])
{
    if (!Game::Instance()->init("kings and pigs", 200, 0, 700, 400, SDL_WINDOW_SHOWN)) {
        return -1;
    }

    Timer timer;

    while (Game::Instance()->running()) {
        timer.restart();

        Game::Instance()->handleEvents();
        Game::Instance()->update();
        Game::Instance()->render();

        timer.pause();
        if (timer.delta() < DELAY_TIME) {
            SDL_Delay(DELAY_TIME - timer.delta());
        }
    }

    Game::Instance()->clean();
    return 0;
}
