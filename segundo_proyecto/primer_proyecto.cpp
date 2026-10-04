#include <iostream>
#ifndef NDEBUG
#endif

#include "raylib.h"

int main(void)
{
	InitWindow(1024, 768, "Segundo proyecto de Luciano");
	SetTargetFPS(60);

	Vector2 posicion = { 50.0f, 50.0f };
	Vector2 velocidad = { 400.0f, 400.0f };
	int contador = 0;
	Color colorPelota = { 60, 60, 60, 100 };

	while (!WindowShouldClose())
	{
		posicion.x += velocidad.x * GetFrameTime();
		posicion.y += velocidad.y * GetFrameTime();

		BeginDrawing();

		ClearBackground({ 255, 255, 255 });

		DrawCircle(posicion.x, posicion.y, 50, colorPelota);

		DrawText(TextFormat("Rebotes: %i", contador), 845, 740, 30, { 0, 0, 0, 255 });

		if (posicion.y > 718)
		{
			velocidad.y = -velocidad.y;
			contador++;
			colorPelota = { 0, 255, 0, 100 };
		}
		else if (posicion.x > 974)
		{
			velocidad.x = -velocidad.x;
			contador++;
			colorPelota = { 0, 0, 255, 100 };
		}
		else if (posicion.y < 50)
		{
			velocidad.y = -velocidad.y;
			contador++;
			colorPelota = { 255, 255, 0, 100 };
		}
		else if (posicion.x < 50)
		{
			velocidad.x = -velocidad.x;
			contador++;
			colorPelota = { 255, 0, 255, 100 };
		}

		EndDrawing();
	}
	CloseWindow();

	return 0;
}