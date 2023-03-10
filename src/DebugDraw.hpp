#pragma once

#include "Box2D.hpp"
#include "Window.hpp"

class DebugDraw final : public b2Draw
{
public:
    DebugDraw(Window* window);

    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

    void DrawCircle(const b2Vec2& center, float radius, const b2Color& color);

    void
    DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color);

    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

    void DrawTransform(const b2Transform& xf);

    void DrawPoint(const b2Vec2& p, float size, const b2Color& color);

private:
    Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
};
