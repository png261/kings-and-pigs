#include "PlayState.hpp"
#include "Box.hpp"
#include "Camera.hpp"
#include "DoorObject.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include "GameObjectFactory.hpp"
#include "GameStateMachine.hpp"
#include "Heart.hpp"
#include "InputHandler.hpp"
#include "LevelParser.hpp"
#include "LoaderParams.hpp"
#include "Pig.hpp"
#include "Player.hpp"


const std::string PlayState::s_stateID = "PLAY";

bool PlayState::onEnter()
{
    if (this->load() == false) {
        return false;
    };


    TheCamera::Instance()->setTarget(Game::Instance()->getPlayer());
    TheCamera::Instance()->setZoom(1.5);

    m_loadingComplete = true;
    return true;
}

bool PlayState::load()
{
    GameObjectFactory::Instance()->registerType("Player", new Creator<Player>);
    GameObjectFactory::Instance()->registerType("Pig", new Creator<Pig>);
    GameObjectFactory::Instance()->registerType("Box", new Creator<Box>);
    GameObjectFactory::Instance()->registerType("Heart", new Creator<Heart>);
    GameObjectFactory::Instance()->registerType("Door", new Creator<DoorObject>);

    TextureManager::Instance()->load("assets/Player/Idle.png", "player idle");
    TextureManager::Instance()->load("assets/Player/Run.png", "player run");
    TextureManager::Instance()->load("assets/Player/Jump.png", "player jump");
    TextureManager::Instance()->load("assets/Player/Attack.png", "player attack");
    TextureManager::Instance()->load("assets/Player/Dead.png", "player dead");
    TextureManager::Instance()->load("assets/Player/Fall.png", "player fall");
    TextureManager::Instance()->load("assets/Player/Ground.png", "player ground");
    TextureManager::Instance()->load("assets/Player/Hit.png", "player hit");
    TextureManager::Instance()->load("assets/Player/Door In.png", "player door in");
    TextureManager::Instance()->load("assets/Player/Door Out.png", "player door out");

    TextureManager::Instance()->load("assets/Enemy/Pig/Idle.png", "pig idle");
    TextureManager::Instance()->load("assets/Enemy/Pig/Run.png", "pig run");
    TextureManager::Instance()->load("assets/Enemy/Pig/Jump.png", "pig jump");
    TextureManager::Instance()->load("assets/Enemy/Pig/Attack.png", "pig attack");
    TextureManager::Instance()->load("assets/Enemy/Pig/Dead.png", "pig dead");
    TextureManager::Instance()->load("assets/Enemy/Pig/Fall.png", "pig fall");
    TextureManager::Instance()->load("assets/Enemy/Pig/Ground.png", "pig ground");
    TextureManager::Instance()->load("assets/Enemy/Pig/Hit.png", "pig hit");

    TextureManager::Instance()->load("assets/Item/Big Heart Idle.png", "heart idle");
    TextureManager::Instance()->load("assets/Item/Big Heart Hit.png", "heart hit");
    TextureManager::Instance()->load("assets/Item/Big Diamond Idle.png", "diamond idle");
    TextureManager::Instance()->load("assets/Item/Big Diamond Hit.png", "diamond hit");

    TextureManager::Instance()->load("assets/Item/Door/idle.png", "door idle");
    TextureManager::Instance()->load("assets/Item/Door/open.png", "door open");
    TextureManager::Instance()->load("assets/Item/Door/close.png", "door close");

    TextureManager::Instance()->load("assets/Item/Box/Idle.png", "box idle");
    TextureManager::Instance()->load("assets/Item/Box/Hit.png", "box hit");

    TextureManager::Instance()->load("assets/UI/Health Bar/Health Bar.png", "health bar");
    TextureManager::Instance()->load("assets/UI/Health Bar/Heart.png", "health heart");

    LevelParser levelParser;
    pLevel = levelParser.parseLevel(
        TheGame::Instance()->getLevelFiles()[TheGame::Instance()->getCurrentLevel() - 1].c_str());
    if (pLevel == nullptr) {
        return false;
    }

    return true;
}

bool PlayState::onExit()
{
    m_exiting = true;
    TheInputHandler::Instance()->reset();

    return true;
}

void PlayState::resume()
{
    m_exiting = false;
}

void PlayState::update()
{
    if (!m_loadingComplete || m_exiting) {
        return;
    }

    if (pLevel != nullptr) {
        pLevel->update();
    }
    TheCamera::Instance()->update();
}

void PlayState::render()
{
    if (!m_loadingComplete || m_exiting) {
        return;
    }

    if (pLevel != nullptr) {
        pLevel->render();
    }
}
