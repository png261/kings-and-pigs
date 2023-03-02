#ifndef MENU_BUTTON_HPP
#define MENU_BUTTON_HPP

#include "GameObject.hpp"
#include "GameObjectFactory.hpp"

class MenuButton : public GameObject
{
public:
    MenuButton();

    virtual ~MenuButton() {}

    virtual void load(const LoaderParams* const pParams);

    virtual void draw();
    virtual void update();

    void setCallback(void (*callback)()) { m_callback = callback; }
    int getCallbackID() { return m_callbackID; }

private:
    enum button_state { MOUSE_OUT = 0, MOUSE_OVER = 1, CLICKED = 2 };

    bool m_bReleased;
    int m_currentFrame;

    int m_callbackID;

    void (*m_callback)();
};

#endif
