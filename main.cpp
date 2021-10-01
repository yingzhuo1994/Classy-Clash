#include "raylib.h"
#include "raymath.h"

int main()
{
    int windowDimensions[2];
    windowDimensions[0] = 384;
    windowDimensions[1] = 384;

    // initialize the window
    InitWindow(windowDimensions[0], windowDimensions[1], "RPG!");

    // map variables
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};
    float speed{4.0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;

        if (Vector2Length(direction) != 0.0)
        {
            // set mapPos = mapPos - direction
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }
  

        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        // stop drawing
        EndDrawing();
    }
    CloseWindow();
}