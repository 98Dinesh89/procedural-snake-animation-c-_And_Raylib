#pragma once
#include <raylib.h>
#include <bits/stdc++.h>

using namespace std;

class Anchor
{
public:
    Vector2 position;
    int sizee;
    int radius;
    Color color = WHITE;

    Anchor(Vector2 pos, int, int sizee);

    void Draw();

    void Update(Vector2 target);
};