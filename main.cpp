#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"

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

    Character knight{windowDimensions[0], windowDimensions[1]};

    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}
    };

    Enemy goblin{
        Vector2{},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")
    };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        // draw the props
        for (auto prop: props)
        {
            prop.Render(knight.getWorldPos());
        }

        knight.tick(GetFrameTime());
        // check map bounds
        if (knight.getWorldPos().x < 0.f
         || knight.getWorldPos().y < 0.f
         || knight.getWorldPos().x + windowDimensions[0] > map.width * mapScale
         || knight.getWorldPos().y + windowDimensions[1] > map.height * mapScale) 
        {
            knight.undoMovement();
        }

        // check prop collisions
        for (auto prop: props)
        {
            if (CheckCollisionRecs(knight.getCollisionRec(), prop.getCollisionRec(knight.getWorldPos())))
            {
                knight.undoMovement();
            }
        }

        goblin.tick(GetFrameTime());
        // stop drawing
        EndDrawing();
    }
    CloseWindow();
}