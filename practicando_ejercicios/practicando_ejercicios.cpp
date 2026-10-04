#include <iostream>
#ifndef NDEBUG
#endif

#include "raylib.h"

int main(void)
{
	InitWindow(800, 600, "ejercicios de practica");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground({ 0,255,255 });

		EndDrawing();
	}
	CloseWindow();

	return 0;
}