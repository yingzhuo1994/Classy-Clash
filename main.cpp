#include "raylib.h"

int main()
{
    int windowDimensions[2];
    windowDimensions[0] = 384;
    windowDimensions[1] = 384;

    // initialize the window
    InitWindow(windowDimensions[0], windowDimensions[1], "RPG!");

    // map variables
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);



        Vector2 mapPos{0.0, 0.0};
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        // stop drawing
        EndDrawing();
    }
    CloseWindow();
}