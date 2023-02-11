#ifndef OBJECT_LAYER_H
#define OBJECT_LAYER_H

#include <iostream>
#include <vector>
#include "Layer.h"

class GameObject;

class ObjectLayer : public Layer
{
public:
    virtual ~ObjectLayer();

    virtual void update(Level* pLevel);
    virtual void render();

    std::vector<GameObject*>* getGameObjects() { return &m_gameObjects; }

private:
    std::vector<GameObject*> m_gameObjects;
};

#endif
