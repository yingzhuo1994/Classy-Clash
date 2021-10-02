#include "raylib.h"
#include "raymath.h"
#include "Character.h"

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
    const float mapScale{4.0};

    Character knight;
    knight.setScreenPos(windowDimensions[0], windowDimensions[1]);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);
        knight.tick(GetFrameTime());
        // check map bounds
        if (knight.getWorldPos().x < 0.f
         || knight.getWorldPos().y < 0.f
         || knight.getWorldPos().x + windowDimensions[0] > map.width * mapScale
         || knight.getWorldPos().y + windowDimensions[1] > map.height * mapScale) 
        {
            knight.undoMovement();
        }
        // stop drawing
        EndDrawing();
    }
    CloseWindow();
}