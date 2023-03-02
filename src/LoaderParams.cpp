#include "LoaderParams.hpp"

LoaderParams::LoaderParams(
    const int x,
    const int y,
    const int width,
    const int height,
    const int textureWidth,
    const int textureHeight,
    const int numFrames,
    const int lives,
    const int callbackID,
    const int textureX,
    const int textureY)
    : m_x(x)
    , m_y(y)
    , m_width(width)
    , m_height(height)
    , m_textureWidth(textureWidth)
    , m_textureHeight(textureHeight)
    , m_textureX(textureX)
    , m_textureY(textureY)
    , m_numFrames(numFrames)
    , m_lives(lives)
    , m_callbackID(callbackID)
{}

int LoaderParams::getX() const
{
    return m_x;
}

int LoaderParams::getY() const
{
    return m_y;
}
int LoaderParams::getWidth() const
{
    return m_width;
}
int LoaderParams::getHeight() const
{
    return m_height;
}
int LoaderParams::getTextureWidth() const
{
    return m_textureWidth;
}
int LoaderParams::getTextureHeight() const
{
    return m_textureHeight;
}
int LoaderParams::getTextureX() const
{
    return m_textureX;
}
int LoaderParams::getTextureY() const
{
    return m_textureY;
}
int LoaderParams::getNumFrames() const
{
    return m_numFrames;
}
int LoaderParams::getLives() const
{
    return m_lives;
}
int LoaderParams::getCallbackID() const
{
    return m_callbackID;
}
