#include <iostream>
#ifndef NDEBUG
#endif

#include "raylib.h"

int main(void)
{
	InitWindow(800, 600, "Primer proyecto de Luciano");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground({0,255,255});

		//(x, y, tamaño, color)
		DrawText("Luciano Flores", 220, 250, 50, DARKGRAY);

		//(donde arranca x, donde arranca y, largo, ancho, color)
		DrawRectangle(150, 300, 525, 5, BLACK);

		if (!IsKeyDown(KEY_SPACE))
		{
			DrawText("Hola mundo!", 265, 350, 50, RED);
		}
		else {
			DrawText("Estoy aprediendo en MAVI!", 60, 350, 50, RED);
		}
		EndDrawing();
	}
	CloseWindow();

	return 0;
}