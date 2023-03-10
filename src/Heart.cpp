#include "Heart.hpp"
#include "Box2D.hpp"
#include "Game.hpp"

void Heart::load(const LoaderParams* const pParams)
{
    ItemObject::load(pParams);
    this->loadAnimation();
}

void Heart::loadAnimation()
{
    m_animations[Animation::IDLE] = new Animation("heart idle", 18, 14, 7);
    m_animations[Animation::HIT] = new Animation("heart hit", 18, 14, 2);

    m_curAnimation = Animation::IDLE;
    m_animations[m_curAnimation]->start();
}

void Heart::bonus()
{
    m_curAnimation = Animation::HIT;
    m_animations[m_curAnimation]->start();
    m_bExist = false;
}

void Heart::update()
{
    ItemObject::update();
}
