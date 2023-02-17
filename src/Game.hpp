#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "Player.hpp"
#include "SDL.hpp"

#include <box2d/box2d.h>

class Game
{
public:
    ~Game(){};
    static Game* Instance();
    bool init(int w, int h, Uint32 flags);
    void handleEvents();
    void update();
    void render();
    void clean();
    void quit();

    SDL_Renderer* getRenderer() const;
    int getCurrentLevel() const;
    int getNextLevel() const;
    int getGameWidth() const;
    int getGameHeight() const;
    int getLevelWidth() const;
    int getLevelHeight() const;
    Player* getPlayer() const;
    b2World* getWorld() const;
    std::vector<std::string> getLevelFiles();

    bool isRunning() const;
    bool isLevelComplete() const;

    void setCurrentLevel(int currentLevel);
    void setNextLevel(int nextLevel);
    void setLevelComplete(bool levelComplete);
    void setLevelWidth(int width);
    void setLevelHeight(int height);
    void setPlayer(Player* pPlayer);

private:
    Game();

    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    b2World* m_pWorld;

    int m_gameWidth;
    int m_gameHeight;

    int m_levelWidth;
    int m_levelHeight;

    int m_currentLevel;
    int m_nextLevel;

    bool m_bRunning;
    bool m_bLevelComplete;

    Player* m_pPlayer;

    std::vector<std::string> m_levelFiles;
};

typedef Game TheGame;

#endif
