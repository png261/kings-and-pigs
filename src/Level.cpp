#include "Level.hpp"
#include "Game.hpp"
#include "Layer.hpp"
#include "TextureManager.hpp"
#include "TileLayer.hpp"

Level::Level() {}

Level::~Level()
{
    for (auto& layer : m_layers) {
        delete layer;
    }

    m_layers.clear();
}

void Level::render()
{
    for (auto& layer : m_layers) {
        layer->render();
    }
}

void Level::update()
{
    for (auto& layer : m_layers) {
        layer->update(this);
    }
}

std::vector<Tileset>* Level::getTilesets()
{
    return &m_tilesets;
}

std::map<int, CollisionShape>* Level::getCollisionShapes()
{
    return &m_collisionShapes;
}

std::vector<Layer*>* Level::getLayers()
{
    return &m_layers;
}

Player* Level::getPlayer()
{
    return m_pPlayer;
}

void Level::setPlayer(Player* player)
{
    m_pPlayer = player;
}
