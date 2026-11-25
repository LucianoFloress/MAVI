#include <iostream>
#ifndef NDEBUG
#endif

#include "raylib.h"

int main(void)
{
	InitWindow(1000, 800, "Trabajo Practico Integrador de Luciano");
	SetTargetFPS(60);

	Texture2D fondo = LoadTexture("sprites/fondo.png");
	Texture2D personaje = LoadTexture("sprites/sprite1.png");
	Texture2D personajeSalto = LoadTexture("sprites/sprite2.png");
	Texture2D plataforma = LoadTexture("sprites/plataforma.png");
	Texture2D fireball = LoadTexture("sprites/fireball.png");

	InitAudioDevice();
	Sound salto = LoadSound("sounds/salto.mp3");

	Vector2 plataformas[8] = {
		{ 10, 700 },
		{ 300, 700 },
		{ 590, 620 },
		{ 300, 500 },
		{ 180, 10 },
		{ 360, 10 },
		{ 420, 10 },
		{ 580, 10 },
	};

	struct Fireball
	{
		Vector2 posicion;
		float velocidad;
		Color color;
	};
	Fireball fireballs[3] = {
		{ { 100, 100 },{ 0 }, WHITE },
		{ { 700, 300 },{ 0 }, WHITE },
		{ { 100, 500 },{ 0 }, WHITE }
	};

	struct Jugador
	{
		Vector2 posicion;
		Vector2 velocidad;
		Color color;
		bool saltando;
		
	};
	Jugador jugador = { { 50, 582 },{ 400.0f, 0.0f }, WHITE, false };

	float gravedad = 800.0f;

	while (!WindowShouldClose())
	{
		//// logica
		float posicionAnteriorY = jugador.posicion.y;
		float posicionAnteriorX = jugador.posicion.x;
		Vector2 mouse = GetMousePosition();

		// gravedad
		jugador.velocidad.y += gravedad * GetFrameTime();
		jugador.posicion.y += jugador.velocidad.y * GetFrameTime();

		// movimiento del jugador
		if (IsKeyDown(KEY_A) && jugador.posicion.x > 0)
		{
			jugador.posicion.x -= jugador.velocidad.x * GetFrameTime();
		};
		if (IsKeyDown(KEY_D) && jugador.posicion.x < 922)
		{
			jugador.posicion.x += jugador.velocidad.x * GetFrameTime();
		};
		if (IsKeyPressed(KEY_R))
		{
			jugador.posicion = { 50, 582 };
			jugador.velocidad.y = 0;
			jugador.saltando = false;
			posicionAnteriorY = jugador.posicion.y;
			posicionAnteriorX = jugador.posicion.x;
		}

		// salto con gravedad
		if (IsKeyPressed(KEY_W) && !jugador.saltando)
		{
			jugador.saltando = true;
			jugador.velocidad.y = -300.0f;
			PlaySound(salto);
		}
		if (jugador.saltando)
		{
			jugador.posicion.y += jugador.velocidad.y * GetFrameTime();
		}

		// colisiones con plataformas
		Rectangle jugadorRect = { jugador.posicion.x, jugador.posicion.y, (float)personaje.width, (float)personaje.height - 5.0f};

		for (int i = 0; i < 8; i++)
		{
			Rectangle plataformaRect = { plataformas[i].x, plataformas[i].y, (float)plataforma.width, (float)plataforma.height };

			if (CheckCollisionRecs(jugadorRect, plataformaRect) && jugador.velocidad.y > 0 && posicionAnteriorY + jugadorRect.height <= plataformaRect.y)
			{
				jugador.posicion.y = plataformaRect.y - jugadorRect.height;
				jugador.velocidad.y = 0;
				jugador.saltando = false;
			}
			if (CheckCollisionRecs(jugadorRect, plataformaRect) && jugador.velocidad.y < 0 && posicionAnteriorY >= plataformaRect.y + plataformaRect.height)
			{
				jugador.posicion.y = plataformaRect.y + plataformaRect.height;
				jugador.velocidad.y = 0;
				jugador.saltando = true;
			}
			if (CheckCollisionRecs(jugadorRect, plataformaRect) && jugador.posicion.x > posicionAnteriorX && posicionAnteriorX + jugadorRect.width <= plataformaRect.x)
			{
				jugador.posicion.x = plataformaRect.x - jugadorRect.width;
			}
			if (CheckCollisionRecs(jugadorRect, plataformaRect) && jugador.posicion.x < posicionAnteriorX && posicionAnteriorX >= plataformaRect.x + plataformaRect.width)
			{
				jugador.posicion.x = plataformaRect.x + plataformaRect.width;
			}

			jugadorRect.x = jugador.posicion.x;
			jugadorRect.y = jugador.posicion.y;
		}

		// dibujo
		BeginDrawing();
		DrawTexture(fondo, 0, 0, WHITE);

		// plataformas
		for (int i = 0; i < 8; i++)
		{
			DrawTexture(plataforma, plataformas[i].x, plataformas[i].y, WHITE);
			// coordenadas de las plataformas
			DrawText(TextFormat("Coordenadas: %.0f, %.0f", plataformas[i].x, plataformas[i].y), plataformas[i].x, plataformas[i].y - 20, 20, WHITE);
		}

		// fireballs
		for (int i = 0; i < 3; i++)
		{
			DrawTexturePro(fireball, { 0, 0, (float)fireball.width, (float)fireball.height }, { fireballs[i].posicion.x, fireballs[i].posicion.y, (float)fireball.width, (float)fireball.height }, { 0, 0 }, 0.0f, fireballs[i].color);
		}

		// personaje
		DrawTexturePro(personaje, { 0, 0, (float)personaje.width, (float)personaje.height }, { jugador.posicion.x, jugador.posicion.y, (float)personaje.width, (float)personaje.height }, { 0, 0 }, 0.0f, jugador.color);
		DrawText(TextFormat("Coordenadas: %.0f, %.0f", jugador.posicion.x, jugador.posicion.y), 10, 10, 20, WHITE);

		//mouse
		DrawText(TextFormat("Mouse X: %.0f | Mouse Y: %.0f", mouse.x, mouse.y), 10, 50, 30, RED);

		EndDrawing();
	}

	UnloadTexture(fondo);
	UnloadTexture(personaje);
	UnloadTexture(personajeSalto);
	UnloadTexture(plataforma);
	UnloadTexture(fireball);
	UnloadSound(salto);

	CloseAudioDevice();
	CloseWindow();

	return 0;
}