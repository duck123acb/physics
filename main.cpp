#include <iostream>
#include <vector>
#include <time.h>
#include "raylib.h"
#include "Ball.hpp"

int main()
{
	srand(time(NULL));
        InitWindow(1000, 600, "physic11!!!");
	SetWindowState(FLAG_VSYNC_HINT);

	std::vector<Ball> balls;
	std::vector<Color> colors = {GRAY, YELLOW, ORANGE, PINK, RED, GREEN, BLUE, VIOLET};

        while (!WindowShouldClose())
        {
		// LOGIC

		if (IsKeyPressed(KEY_SPACE)) balls.push_back(Ball(GetMouseX(), GetMouseY(), 16, rand() % 600 + 100, colors[rand() % colors.size()]));

		for (long unsigned int i = 0; i < balls.size(); i++)
		{
			balls[i].move();
			if (balls[i].bounceImpulse == 0) balls.erase(balls.begin() + i);
		}

		// DRAWING

		BeginDrawing();

                ClearBackground(BLACK);
                DrawFPS(10, 10);

                for (long unsigned int i = 0; i < balls.size(); i++)
                {
			balls[i].draw();
                }

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
