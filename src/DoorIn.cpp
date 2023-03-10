#include "DoorIn.hpp"
#include "Game.hpp"

void DoorIn::load(const LoaderParams* const pParams)
{
    Door::load(pParams);
    this->createSensor();
    b2Filter filter;
    filter.categoryBits = Box2D::CAT_DOOR_IN;
    filter.maskBits = Box2D::MASK_DOOR_IN;
    m_pFixture->SetFilterData(filter);
}

void DoorIn::createSensor()
{
    float sensorSize = 5;
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(
        Box2D::pixelToMeter(sensorSize) / 2.0f,
        Box2D::pixelToMeter(sensorSize) / 2.0f,
        b2Vec2(
            Box2D::pixelToMeter(m_width / 4.0f - sensorSize),
            Box2D::pixelToMeter(m_height / 4.0f - sensorSize)),
        0);

    b2FixtureDef sensorDef;
    sensorDef.shape = &dynamicBox;
    sensorDef.isSensor = true;
    sensorDef.filter.categoryBits = Box2D::CAT_DOOR_IN;
    sensorDef.filter.maskBits = Box2D::MASK_DOOR_IN;
    m_pBody->CreateFixture(&sensorDef);
}

void DoorIn::open()
{
    Door::open();
    if (m_animations[Animation::DOOR_OPEN]->isFinished()) {
        Game::Instance()->nextLevel();
    }
}
