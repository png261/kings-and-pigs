#include "Heart.hpp"
#include <iostream>
#include "Collision.hpp"
#include "Game.hpp"

void Heart::load(const LoaderParams* pParams)
{
    ItemObject::load(pParams);

    m_animations[IDLE] = new Animation("heart idle", 7);
    m_animations[HIT] = new Animation("heart hit", 2);

    m_curAnimation = IDLE;
    m_animations[m_curAnimation]->start();
}

void Heart::bonus()
{
    Game::Instance()->getPlayer()->changeLives(+1);
}

void Heart::update()
{
    if (Collision::check(this, Game::Instance()->getPlayer())) {
        bonus();
        m_animations[m_curAnimation]->stop();
        m_curAnimation = HIT;
        m_animations[m_curAnimation]->start();
        m_bDead = true;
    }

    ItemObject::update();
}

void Heart::clean() {}
