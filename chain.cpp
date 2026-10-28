#include "chain.hpp"
#include <bits/stdc++.h>
#include <raylib.h>
#include <raymath.h>

Chain::Chain(int count, Vector2 startPos, int radius, int speed, int Size)
{
    Speed = speed;
    firstRadius = radius;
    Sizee = Size;

    Anchor start({startPos.x, startPos.y}, radius, Sizee);
    anchors.push_back(start);

    for (int i = 1; i < count; i++)
    {
        Anchor temp = anchors[i - 1];
        anchors.push_back(Anchor({temp.position.x, temp.position.y + (2 * radius)}, radius, Sizee));
    }
}

void Chain::Draw()
{
    for (int i = 0; i < anchors.size(); i++)
    {
        anchors[i].Draw();
    }

    for (int i = 0; i < anchors.size() - 1; i++)
    {

        Vector2 p1 = anchors[i].position;
        Vector2 p2 = anchors[i + 1].position;

        Vector2 dir = Vector2Normalize(Vector2Subtract(p2, p1));

        Vector2 perp = {-dir.y, dir.x};

        float r1 = anchors[i].sizee;
        float r2 = anchors[i + 1].sizee;

        Vector2 left1 = Vector2Add(p1, Vector2Scale(perp, r1));
        Vector2 right1 = Vector2Subtract(p1, Vector2Scale(perp, r1));

        Vector2 left2 = Vector2Add(p2, Vector2Scale(perp, r2));
        Vector2 right2 = Vector2Subtract(p2, Vector2Scale(perp, r2));

        DrawTriangle(left1, left2, right1, WHITE);
        DrawTriangle(right1, left2, right2, WHITE);

        if (i == 1)
        {
            DrawCircle(left1.x, left1.y, 4, GRAY);
            DrawCircle(right1.x, right1.y, 4, GRAY);
        }
    }
}

void Chain::Update(Vector2 target)
{
    for (int i = 1; i < anchors.size(); i++)
    {
        anchors[i].Update(target);
        target = anchors[i].position;
    }
}

void Chain::UpdateFollowMe()
{

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        Vector2 target = GetMousePosition();

        float dx = target.x - anchors[0].position.x;
        float dy = target.y - anchors[0].position.y;
        float distance = sqrt(dx * dx + dy * dy);
        if (distance < 0.001f)
            return;
        float toMove = Speed;
        if (distance > Speed)
        {
            toMove += (Speed * distance) / 200;
        }
        if (distance < Speed)
        {
            toMove = 0;
        }

        float nx = dx / distance;
        float ny = dy / distance;

        anchors[0].position.x += toMove * nx;
        anchors[0].position.y += toMove * ny;

        Update(anchors[0].position);
    }

    if (IsKeyDown(KEY_UP))
    {
        anchors[0].position.y -= Speed;
        Update(anchors[0].position);
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        anchors[0].position.y += Speed;
        Update(anchors[0].position);
    }

    if (IsKeyDown(KEY_LEFT))
    {
        anchors[0].position.x -= Speed;
        Update(anchors[0].position);
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        anchors[0].position.x += Speed;
        Update(anchors[0].position);
    }
}

void Chain::UpdateAngle()
{
    for (int i = 0; i < anchors.size(); i++)
    {
        int x1 = anchors[i].position.x - anchors[i + 1].position.x;
        int x2 = anchors[i + 1].position.x - anchors[i + 1].position.x;
        int y1 = anchors[i].position.y - anchors[i + 1].position.y;
        int y2 = anchors[i + 1].position.y - anchors[i + 2].position.y;
        Vector2 v1 = {x1, y1};
        Vector2 v2 = {x2, y2};

        float m1 = sqrt(x1 * x1 + y1 * y1);
        float m2 = sqrt(x2 * x2 + y2 * y2);

        float dot = x1 * x2 + y1 * y2;
        dot /= m1 * m2;

        float angle = acos(dot) * 180.0 / PI;

        if (angle <= 30)
        {
        }
    }
}

void Chain::AddAnchor(int sizee)
{
    int last = anchors.size() - 1;

    anchors.push_back(Anchor({anchors[last].position.x, anchors[last].position.y + (firstRadius)}, firstRadius, sizee));
}
