#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(1000, 980, "raylib Tetris");
    //    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    double deltaTime = 0.0;
    double lastFrameTime = GetTime();

    while (!WindowShouldClose())
    {
        double currentFrameTime = GetTime();
        deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;

        // Calculate FPS
        int currentFPS = static_cast<int>(1.0 / deltaTime);

        UpdateMusicStream(game.music);
        game.manejo_movimiento_teclado();
        if (EventTriggered(0.29))
        {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextEx(font, "Score", {765, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {770, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {720, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({720, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {720 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        // DrawRectangleRounded({220, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();

        DrawText(("FPS: " + std::to_string(currentFPS)).c_str(), 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
}
