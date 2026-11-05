#include <iostream>
#ifndef NDEBUG
#endif

#include "raylib.h"

int main(void)
{
	InitWindow(800, 600, "Cuarto Proyecto de Luciano");
	InitAudioDevice();
	SetTargetFPS(60);
	HideCursor();

	// Cargo recursos
	Texture2D fondo = LoadTexture("sprites/fondo.png");
	Texture2D personaje = LoadTexture("sprites/sprite1.png");
	Sound salto = LoadSound("sounds/salto.mp3");

	// Variables para la posicion del personaje y del mouse
	Vector2 posicionPersonaje = { 150, 415 };
	Vector2 posicionMouse = { 0, 0 };

	// Variables para el salto
	bool saltando = false;
	bool subiendo = false;
	float velocidadSalto = 300.0f;

	// Variable para mostrar mensaje de sistema
	bool mostrarMensaje = true;

	// Variables para el boton
	Vector2 botonPos = { 550, 150 };
	Vector2 botonTam = { 75, 75 };
	bool botonPresionado = false;
	Color colorFon = WHITE;

	while (!WindowShouldClose())
	{
		// Posicion del mouse
		posicionMouse = GetMousePosition();

		// Movimiento en el eje X del personaje
		if (IsKeyDown(KEY_LEFT) && posicionPersonaje.x > 0)
		{
			posicionPersonaje.x -= 5;
		}
		if (IsKeyDown(KEY_RIGHT) && posicionPersonaje.x < 722)
		{
			posicionPersonaje.x += 5;
		}

		// detecto el salto
		if (IsKeyPressed(KEY_SPACE) && !saltando)
		{
			saltando = true;
			subiendo = true;
			PlaySound(salto);
		}
		// controlo el salto
		if (saltando)
		{
			if (subiendo)
			{
				posicionPersonaje.y -= velocidadSalto * GetFrameTime();
				// altura máxima del salto
				if (posicionPersonaje.y <= 325)
				{
					subiendo = false;
				}
			}
			else
			{
				posicionPersonaje.y += velocidadSalto * GetFrameTime();
				// limite del suelo
				if (posicionPersonaje.y >= 415)
				{
					posicionPersonaje.y = 415;
					saltando = false;
				}
			}
		}

		// reiniciar posicion personaje
		if (IsKeyPressed(KEY_R))
		{
			posicionPersonaje = { 150, 415 };
		}

		// mostrar mensaje de sistema
		if (IsKeyPressed(KEY_M))
		{
			mostrarMensaje = !mostrarMensaje;
		}

		// detecto el mouse
		if (CheckCollisionPointRec(posicionMouse, { botonPos.x, botonPos.y, botonTam.x, botonTam.y }))
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				botonPresionado = !botonPresionado;
				colorFon = { (unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), 255 };
			}
		}

		// Dibujar la escena
		BeginDrawing();

		DrawTexture(fondo, 0, 0, colorFon);
		DrawTextureEx(personaje, posicionPersonaje, 0.0f, 1.0f, WHITE);

		// debbuging util
		DrawText(TextFormat("Posición del mouse: (%.0f, %.0f)", posicionMouse.x, posicionMouse.y), 10, 10, 20, WHITE);
		DrawText(TextFormat("Posición del personaje: (%.0f, %.0f)", posicionPersonaje.x, posicionPersonaje.y), 10, 30, 20, WHITE);
		
		if (mostrarMensaje)
		{
			DrawText("Controles: Flechas izquierda/derecha para mover, Espacio para saltar, R \npara reiniciar, M para mostrar/ocultar este mensaje", 10, 50, 20, WHITE);
		}

		DrawRectangle(botonPos.x, botonPos.y, botonTam.x, botonTam.y, YELLOW);
		DrawText("Boton", botonPos.x + 10, botonPos.y + 25, 20, BLACK);
		DrawCircleV(posicionMouse, 8, RED);
		
		EndDrawing();
	}

	UnloadTexture(fondo);
	UnloadTexture(personaje);
	UnloadSound(salto);
	CloseAudioDevice();
	CloseWindow();

	return 0;
}