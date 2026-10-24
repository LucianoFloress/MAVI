#include <iostream>
#ifndef NDEBUG
#endif

#include "raylib.h"

class sprites
{
public:
	Vector2 posicion = { 0, 0 };
	float escala = 0.0f;
	Color color;

	sprites(Vector2 pos, float esc, Color col)
	{
		posicion = pos;
		escala = esc;
		color = col;
	};
};

int main(void)
{
	InitWindow(800, 600, "Tercer Proyecto de Luciano");
	SetTargetFPS(60);

	// cargo la textura del sprite
	Texture2D textura = LoadTexture("sprites/sprite1.png");
	SetTextureFilter(textura, TEXTURE_FILTER_BILINEAR);

	// creo los vectores de posicion y escala y color para cada sprite
	sprites sprite1({ 350, 100 }, 1.0f, WHITE);
	sprites sprite2({ 200, 320 }, 1.5f, BLUE);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground({ 0,255,255 });

		// dibujo los sprites		
		DrawTextureEx(textura, sprite1.posicion, 0.0f, sprite1.escala, sprite1.color);
		DrawTextureEx(textura, sprite2.posicion, 0.0f, sprite2.escala, sprite2.color);

		// dibujo la informacion de cada sprite
		DrawText(TextFormat("Sprite 1: Escala: %.1f, Posicion: %.0f, %.0f, RGB: %d, %d, %d", sprite1.escala, sprite1.posicion.x, sprite1.posicion.y, sprite1.color.r, sprite1.color.g, sprite1.color.b), 10, 10, 20, BLACK);
		DrawText(TextFormat("Sprite 2: Escala: %.1f, Posicion: %.0f, %.0f, RGB: %d, %d, %d", sprite2.escala, sprite2.posicion.x, sprite2.posicion.y, sprite2.color.r, sprite2.color.g, sprite2.color.b), 10, 570, 20, BLACK);

		DrawText("Presiona la barra espaciadora para intercambiar las propiedades. \nApliqué movimiento solamente al sprite1", 10, 40, 20, BLACK);

		EndDrawing();

		// swap visual de los sprites al presionar la barra espaciadora
		if (IsKeyPressed(KEY_SPACE))
		{
			// guardo valores temporalmente
			Vector2 tempPos = sprite1.posicion;
			float tempEsc = sprite1.escala;
			Color tempCol = sprite1.color;
			// hago el swap
			sprite1.posicion = sprite2.posicion;
			sprite2.posicion = tempPos;
			sprite1.escala = sprite2.escala;
			sprite2.escala = tempEsc;
			sprite1.color = sprite2.color;
			sprite2.color = tempCol;
		}

		// calculo los limites de la pantalla para el sprite1
		float anchoSprite = textura.width * sprite1.escala;
		float altoSprite = textura.height * sprite1.escala;
		float limiteDerecho = GetScreenWidth() - anchoSprite; // -> 722
		float limiteInferior = GetScreenHeight() - altoSprite; // -> 477

		// movimiento del sprite1
		if (IsKeyDown(KEY_W))
		{
			sprite1.posicion.y -= 10.0f;
		}
		if (IsKeyDown(KEY_S))
		{
			sprite1.posicion.y += 10.0f;
		}
		if (IsKeyDown(KEY_A))
		{
			sprite1.posicion.x -= 10.0f;
		}
		if (IsKeyDown(KEY_D))
		{
			sprite1.posicion.x += 10.0f;
		}
		// marco los limites
		if (sprite1.posicion.x < 0)
		{
			sprite1.posicion.x = 0;
		}
		if (sprite1.posicion.x > limiteDerecho)
		{
			sprite1.posicion.x = limiteDerecho;
		}
		if (sprite1.posicion.y < 0)
		{
			sprite1.posicion.y = 0;
		}
		if (sprite1.posicion.y > limiteInferior)
		{
			sprite1.posicion.y = limiteInferior;
		}
	}

	// libero la memoria de la textura
	UnloadTexture(textura);
	CloseWindow();

	return 0;
}