#ifndef BOX_HPP
#define BOX_HPP

#include "DamageableObject.hpp"
#include "Enemy.hpp"


class Box : public Enemy, public DamageableObject
{
public:
    Box();
    ~Box() {}

    void load(const LoaderParams* pParams);

    void draw();
    void update();
    void clean();
    void updateAnimation();

    std::string type() const { return "Box"; }
};

#endif
