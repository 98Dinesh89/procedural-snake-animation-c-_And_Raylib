#pragma once
#include <raylib.h>
#include <bits/stdc++.h>
#include "anchor.hpp"

using namespace std;

class Chain
{
public:
    vector<Anchor> anchors = {};
    int firstRadius;
    int Speed;
    int Sizee;

    Chain(int count, Vector2 startPos, int radius, int speed, int Size);

    void Draw();

    void Update(Vector2 target);
    void UpdateFollowMe();
    void UpdateAngle();

    void AddAnchor(int sizee);
};