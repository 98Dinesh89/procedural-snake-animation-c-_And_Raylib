#include <iostream>
#include <bits/stdc++.h>
#include <raylib.h>
#include "chain.hpp"

using namespace std;

void Snake(Chain &chain, int i)
{
    chain.AddAnchor(i - 3);
    int j = i;
    while (j >= 2)
    {
        chain.AddAnchor(j);
        chain.AddAnchor(j);
        chain.AddAnchor(j);
        j--;
    }
    // chain.AddAnchor(i + 10);
    // chain.AddAnchor(i + 10);
    // chain.AddAnchor(i + 9);
    // chain.AddAnchor(i + 9);
    // chain.AddAnchor(i + 9);
    // chain.AddAnchor(i + 9);
    // chain.AddAnchor(i + 9);
    // chain.AddAnchor(i + 8);
    // chain.AddAnchor(i + 8);
    // chain.AddAnchor(i + 8);
    // chain.AddAnchor(i + 8);
    // chain.AddAnchor(i + 8);
    // chain.AddAnchor(i + 7);
    // chain.AddAnchor(i + 7);
    // chain.AddAnchor(i + 7);
    // chain.AddAnchor(i + 7);
    // chain.AddAnchor(i + 7);
    // chain.AddAnchor(i + 6);
    // chain.AddAnchor(i + 6);
    // chain.AddAnchor(i + 6);
    // chain.AddAnchor(i + 6);
    // chain.AddAnchor(i + 6);
    // chain.AddAnchor(i + 5);
    // chain.AddAnchor(i + 5);
    // chain.AddAnchor(i + 5);
    // chain.AddAnchor(i + 5);
    // chain.AddAnchor(i + 5);
    // chain.AddAnchor(i + 4);
    // chain.AddAnchor(i + 4);
    // chain.AddAnchor(i + 4);
    // chain.AddAnchor(i + 4);
    // chain.AddAnchor(i + 3);
    // chain.AddAnchor(i + 3);
    // chain.AddAnchor(i + 3);
    // chain.AddAnchor(i + 2);
    // chain.AddAnchor(i + 2);
    // chain.AddAnchor(i + 2);
    // chain.AddAnchor(i + 1);
    // chain.AddAnchor(i + 1);
}

int main()
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    Vector2 startPos = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    int srartRadius = 20;
    int sizee = 9;
    int speed = 7;

    // Chain
    Chain chain(1, startPos, srartRadius, speed, sizee);
    Snake(chain, 20);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Procedural Animation");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {

        // 1. Event Handeling

        // 2. Updating
        chain.UpdateFollowMe();

        // 3. Drawing
        BeginDrawing();
        ClearBackground(BLACK);
        chain.Draw();
        EndDrawing();
    }

    CloseWindow();
}