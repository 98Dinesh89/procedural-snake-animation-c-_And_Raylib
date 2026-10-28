#include "anchor.hpp"

Anchor::Anchor(Vector2 pos, int r, int size)
{
    position = pos;
    radius = r;
    sizee = size;
}

void Anchor::Draw()
{
    DrawCircle(position.x, position.y, sizee, color);
}

void Anchor::Update(Vector2 target)
{
    float dx = target.x - position.x;
    float dy = target.y - position.y;
    float distance = sqrt(dx * dx + dy * dy);
    if (distance < 0.001f)
        return;
    float toMove = distance - radius;

    float nx = dx / distance;
    float ny = dy / distance;

    position.x += toMove * nx;
    position.y += toMove * ny;
}
