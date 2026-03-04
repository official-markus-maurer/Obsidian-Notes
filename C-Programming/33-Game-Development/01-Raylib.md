# Raylib

Raylib is a simple and easy-to-use library to enjoy videogame programming. No weird setup, no dependencies hell.

## 🎮 Basic Game Loop

```c
#include "raylib.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib - Basic C Game");
    SetTargetFPS(60);

    // Game variables
    int ballX = 400;
    int ballY = 225;

    while (!WindowShouldClose()) {
        // 1. Update
        if (IsKeyDown(KEY_RIGHT)) ballX += 2;
        if (IsKeyDown(KEY_LEFT)) ballX -= 2;

        // 2. Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Move the ball with ARROW KEYS", 10, 10, 20, DARKGRAY);
            DrawCircle(ballX, ballY, 20, MAROON);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
```

## 📦 Features
-   3D Shapes (`DrawCube`, `DrawSphere`)
-   Audio (`InitAudioDevice`, `PlaySound`)
-   Models and Shaders

---
[[00-Index|Back to GameDev Index]]
