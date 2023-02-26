#include "AttackableObject.hpp"
AttackableObject::AttackableObject(int damage, int range, int attackSpeed)
    : m_damage(damage)
    , m_range(range)
    , m_bAttack(false)
    , m_bCanAttack(true)
    , m_attackSpeed(attackSpeed)
    , m_pAttackSensor(nullptr)
{}

void AttackableObject::createAttackSensor(
    b2Body* pBody,
    int objectWidth,
    Box2D::collisionFilterMask filterMask)
{
    b2PolygonShape attackShape;
    attackShape.SetAsBox(m_range / 2.0f, m_range / 2.0f, b2Vec2(objectWidth / 4.0f, 0), 0);
    b2FixtureDef attackSensorDef;
    attackSensorDef.shape = &attackShape;
    attackSensorDef.friction = 0;
    attackSensorDef.density = 0;
    attackSensorDef.filter.categoryBits = Box2D::CAT_ATTACK_SENSOR;
    attackSensorDef.filter.maskBits = filterMask;
    attackSensorDef.isSensor = true;
    m_pAttackSensor = pBody->CreateFixture(&attackSensorDef);
}

bool AttackableObject::isAttack()
{
    return m_bAttack;
}

bool AttackableObject::canAttack()
{
    return m_bCanAttack;
}

int AttackableObject::getDamage()
{
    return m_damage;
}

void AttackableObject::attack()
{
    if (isAttack() || canAttack() == false) {
        return;
    }

    m_bAttack = true;
    m_bCanAttack = false;
    attackTimer.start();
}

void AttackableObject::update()
{
    if (attackTimer.delta() >= m_attackSpeed) {
        m_bAttack = false;
        m_bCanAttack = true;
        attackTimer.stop();
    }
}