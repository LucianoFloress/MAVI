#include <iostream>
#ifndef NDEBUG
#endif

#include "raylib.h"

/* limpio
int main(void)
{
	InitWindow(1024, 768, "Ejercicios de practica");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground({ 255,255,255 });

		EndDrawing();
	}
	CloseWindow();

	return 0;
}
*/

/*
int main(void)
{
	InitWindow(1024, 768, "Ejercicios de practica");
	SetTargetFPS(60);

	Vector2 posicion = { 35.0f, 35.0f };
	Vector2 velocidad = { 5.0f, 5.0f };

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground({ 255,255,255 });

		DrawCircle(posicion.x, posicion.y, 35, { 255,0,0,255 });
		//evaluo si la tecla shift esta presionada para aumentar la velocidad del circulo
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			velocidad.x = 10.0f;
			velocidad.y = 10.0f;
		}
		else if (IsKeyDown(KEY_SPACE))
		{
			velocidad.y = 2.5f;
			velocidad.x = 2.5f;
		}
		else {
			velocidad.x = 5.0f;
			velocidad.y = 5.0f;
		}
		// evaluo si las teclas de movimiento estan presionadas y si el circulo no se sale de la pantalla
		if (IsKeyDown(KEY_W) && posicion.y > 35.0f)
		{
			posicion.y -= velocidad.y;
		}
		if (IsKeyDown(KEY_S) && posicion.y < 733.0f)
		{
			posicion.y += velocidad.y;
		}
		if (IsKeyDown(KEY_A) && posicion.x > 35.0f)
		{
			posicion.x -= velocidad.x;
		}
		if (IsKeyDown(KEY_D) && posicion.x < 989.0f)
		{
			posicion.x += velocidad.x;
		}

		DrawText(TextFormat("Posicion: X: %.2f, Y: %.2f", posicion.x, posicion.y), 10, 10, 20, { 0,0,0,255 });
		DrawText(TextFormat("Velocidad: X: %.2f, Y: %.2f", velocidad.x, velocidad.y), 10, 40, 20, { 0,0,0,255 });


		EndDrawing();
	}
	CloseWindow();

	return 0;
}
*/
/*
int main(void)
{
	InitWindow(1024, 768, "Ejercicios de practica");
	SetTargetFPS(60);

	Vector2 posicionPelota = { 35.0f, 35.0f };
	Vector2 velocidadPelota = { 400.0f, 400.0f };
	Color colorPelota = RED;
	Vector2 posicionCuadrado = { (float)GetRandomValue(50, 974), (float)GetRandomValue(50, 718) };
	int contador = 0;
	int contadorToques = 0;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground({ 255,255,255 });

		posicionPelota.y += velocidadPelota.y * GetFrameTime();
		posicionPelota.x += velocidadPelota.x * GetFrameTime();

		DrawCircle(posicionPelota.x, posicionPelota.y, 35, colorPelota);
		DrawRectangle(posicionCuadrado.x, posicionCuadrado.y, 100, 100, BLUE);

		if (posicionPelota.y > 733 || posicionPelota.y < 35)
		{
			velocidadPelota.y = -velocidadPelota.y;
		}
		if (posicionPelota.x > 989 || posicionPelota.x < 35)
		{
			velocidadPelota.x = -velocidadPelota.x;
		}

		if (CheckCollisionCircleRec(posicionPelota, 35, { posicionCuadrado.x, posicionCuadrado.y, 100, 100 }))
		{
			contador++;
			posicionCuadrado.x = (float)GetRandomValue(100, 924);
			posicionCuadrado.y = (float)GetRandomValue(100, 668);
			colorPelota = { (unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), 255 };
			contadorToques++;
			if (contadorToques == 5 && contador < 35)
			{
				if (velocidadPelota.x > 0 && velocidadPelota.y > 0)
				{
					velocidadPelota.x += 400.0f;
					velocidadPelota.y += 400.0f;
					contadorToques = 0;
				}
				else if (velocidadPelota.x < 0 && velocidadPelota.y < 0)
				{
					velocidadPelota.x -= 400.0f;
					velocidadPelota.y -= 400.0f;
					contadorToques = 0;
				}
				else if (velocidadPelota.x > 0 && velocidadPelota.y < 0)
				{
					velocidadPelota.x += 400.0f;
					velocidadPelota.y -= 400.0f;
					contadorToques = 0;
				}
				else if (velocidadPelota.x < 0 && velocidadPelota.y > 0)
				{
					velocidadPelota.x -= 400.0f;
					velocidadPelota.y += 400.0f;
					contadorToques = 0;
				}
			}
		}

		DrawText(TextFormat("Velocidad: X: %.2f, Y: %.2f", velocidadPelota.x, velocidadPelota.y), 10, 10, 20, BLACK);
		DrawText(TextFormat("Contador: %i", contador), 10, 40, 20, BLACK);
		DrawText(TextFormat("Contador de toques: %i", contadorToques), 10, 70, 20, BLACK);

		EndDrawing();
	}
	CloseWindow();

	return 0;
}
*/
/*
class Pelotas
{
public:
	Vector2 posicion = { 0, 0 };
	Vector2 velocidad = { 0, 0 };
	Color colorPelota = { 0, 0, 0, 255 };
	int radio = 0;

	Pelotas() {}
};

int main(void)
{
	InitWindow(1024, 768, "Ejercicios de practica");
	SetTargetFPS(60);

	Pelotas arrayPelotas[5];

	for (int i = 0; i < 5; i++)
	{
		arrayPelotas[i].posicion = { 500, 380 };
		arrayPelotas[i].velocidad = { (float)GetRandomValue(-300, 300), (float)GetRandomValue(-300, 300) };
		arrayPelotas[i].colorPelota = { (unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), 255 };
		arrayPelotas[i].radio = 50;
	}

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground({ 255,255,255 });

		for (int i = 0; i < 5; i++)
		{
			arrayPelotas[i].posicion.y += arrayPelotas[i].velocidad.y * GetFrameTime();
			arrayPelotas[i].posicion.x += arrayPelotas[i].velocidad.x * GetFrameTime();

			DrawCircle(arrayPelotas[i].posicion.x, arrayPelotas[i].posicion.y, arrayPelotas[i].radio, arrayPelotas[i].colorPelota);

			if (arrayPelotas[i].posicion.y > 743 || arrayPelotas[i].posicion.y < 50)
			{
				arrayPelotas[i].velocidad.y = -arrayPelotas[i].velocidad.y;
			}
			if (arrayPelotas[i].posicion.x > 974 || arrayPelotas[i].posicion.x < 50)
			{
				arrayPelotas[i].velocidad.x = -arrayPelotas[i].velocidad.x;
			}
		}

		EndDrawing();
	}
	CloseWindow();

	return 0;
}
*/
/*
int main(void)
{
	InitWindow(1024, 768, "Ejercicios de practica");
	SetTargetFPS(60);

	Vector2 posicionJugador = { (float)GetRandomValue(50, 974), (float)GetRandomValue(50, 718) };
	Vector2 velocidadJugador = { 10.0f, 10.0f };
	Vector2 posicionCuadrado = { (float)GetRandomValue(50, 974), (float)GetRandomValue(50, 718) };
	int contador = 0;
	double inicio = GetTime();
	bool juegoPusado = false;
	double tiempoTranscurrido = 0;

	while (!WindowShouldClose())
	{
		DrawText(TextFormat("Tiempo transcurrido: %.2f", tiempoTranscurrido), 10, 70, 20, { 255,255,255,255 });

		if (!juegoPusado)
		{
			tiempoTranscurrido = GetTime() - inicio;
			if (tiempoTranscurrido >= 30)
			{
				tiempoTranscurrido = 30;
				juegoPusado = true;
			}

			// con estos if, muevo el cuadrado con las teclas W, A, S, D y no me deja salirme de la pantalla, y con el segundo if, me aseguro de que no se salga de la pantalla, aunque la velocidad sea mayor a la distancia que queda hasta el borde.
			if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) && posicionJugador.y > 0)
			{
				posicionJugador.y -= velocidadJugador.y;
				if (posicionJugador.y < 0)
				{
					posicionJugador.y = 0;
				}
			}
			if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S) && posicionJugador.y < 718)
			{
				posicionJugador.y += velocidadJugador.y;
				if (posicionJugador.y > 718)
				{
					posicionJugador.y = 718;
				}
			}
			if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A) && posicionJugador.x > 0)
			{
				posicionJugador.x -= velocidadJugador.x;
				if (posicionJugador.x < 0)
				{
					posicionJugador.x = 0;
				}
			}
			if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D) && posicionJugador.x < 974 )
			{
				posicionJugador.x += velocidadJugador.x;
				if (posicionJugador.x > 974)
				{
					posicionJugador.x = 974;
				}
			}
			if (CheckCollisionRecs({ posicionJugador.x, posicionJugador.y, 50, 50 }, { posicionCuadrado.x, posicionCuadrado.y, 50, 50 }))
			{
				contador++;
				posicionCuadrado.x = (float)GetRandomValue(50, 974);
				posicionCuadrado.y = (float)GetRandomValue(50, 718);
			}
		}

		BeginDrawing();
		ClearBackground({ 0,0,0 });

		DrawRectangle(posicionJugador.x, posicionJugador.y, 50, 50, WHITE);
		DrawText(TextFormat("Posicion: X: %.2f, Y: %.2f", posicionJugador.x, posicionJugador.y), 10, 10, 20, { 255,255,255,255 });

		DrawRectangle(posicionCuadrado.x, posicionCuadrado.y, 50, 50, RED);

		DrawText(TextFormat("Contador: %i", contador), 10, 40, 20, { 255,255,255,255 });

		if (juegoPusado)
		{
			DrawText("GAME OVER", 380, 365, 40, BLUE);
			DrawText(TextFormat("Puntaje: %i", contador), 445, 410, 20, BLUE);
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
*/

class jugador
{
public:
	Vector2 posicion = { 0,0 };
	float velocidad = 0.0f;
	Color color = { 0,0,0,255 };
	Vector2 largoAlto = { 0,0 };
	int puntaje = 0;

	jugador(Vector2 pos, float vel, Color col, Vector2 lAlto, int puntuacion)
	{
		posicion = pos;
		velocidad = vel;
		color = col;
		largoAlto = lAlto;
		puntaje = puntuacion;
	};
};

int main(void)
{
	InitWindow(1024, 768, "Ejercicios de practica");
	SetTargetFPS(60);


	jugador jugador1({ 462, 0 }, 10.0f, { 255,255,255,255 }, { 100,20 }, 0);
	jugador jugador2({ 462, 748 }, 10.0f, { 255,255,255,255 }, { 100,20 }, 0);
	Vector2 posicionPelota = { 512, 35 };
	Vector2 velocidadPelota = { (float)GetRandomValue(-300.0f, 300.0f), 300.0f };
	bool pelotaEnMovimiento = false;

	while (!WindowShouldClose())
	{
		// movimiento de los jugadores
		if (IsKeyDown(KEY_A) && jugador1.posicion.x > 0)
		{
			jugador1.posicion.x -= 10.0f;
		}
		if (IsKeyDown(KEY_D) && jugador1.posicion.x < 924)
		{
			jugador1.posicion.x += 10.0f;
		}
		if (IsKeyDown(KEY_RIGHT) && jugador2.posicion.x < 924)
		{
			jugador2.posicion.x += 10.0f;
		}
		if (IsKeyDown(KEY_LEFT) && jugador2.posicion.x > 0)
		{
			jugador2.posicion.x -= 10.0f;
		}

		// movimiento de la pelota
		if (IsKeyPressed(KEY_SPACE))
		{
			pelotaEnMovimiento = true;
		}
		if (pelotaEnMovimiento)
		{
			posicionPelota.y += velocidadPelota.y * GetFrameTime();
			posicionPelota.x += velocidadPelota.x * GetFrameTime();
		}
		// contador de puntaje de los jugadores, al llegar a los bordes superior e inferior, la pelota vuelve a la posicion inicial y se reinicia el movimiento de la pelota, generando un movimiento aleatorio en el eje x y un movimiento fijo en el eje y, dependiendo de si la pelota va hacia arriba o hacia abajo.
		if (posicionPelota.y > 753)
		{
			jugador1.puntaje++;
			pelotaEnMovimiento = false;
			velocidadPelota = { (float)GetRandomValue(-300.0f, 300.0f), 300.0f };
			//posicionPelota = { jugador1.posicion.x+50, 35 };
		}
		if (posicionPelota.y < 15)
		{
			jugador2.puntaje++;
			pelotaEnMovimiento = false;
			posicionPelota = { jugador2.posicion.x+50, 733 };
			velocidadPelota = { (float)GetRandomValue(-300.0f, 300.0f), -300.0f };
		}
		// rebote de la pelota en los bordes izq y der.
		if (posicionPelota.x > 1009 || posicionPelota.x < 15)
		{
			velocidadPelota.x = -velocidadPelota.x;
		}
		// rebote de la pelota en las paletas de los jugadores
		if (CheckCollisionCircleRec(posicionPelota, 15, { jugador1.posicion.x, jugador1.posicion.y, jugador1.largoAlto.x, jugador1.largoAlto.y }))
		{
			velocidadPelota.y = -velocidadPelota.y;
		}
		if (CheckCollisionCircleRec(posicionPelota, 15, { jugador2.posicion.x, jugador2.posicion.y, jugador2.largoAlto.x, jugador2.largoAlto.y }))
		{
			velocidadPelota.y = -velocidadPelota.y;
		}
		// movimiento de la pelota, que siga la paleta del jugador 1 o 2 si la pelota no esta en movimiento
		

		BeginDrawing();
		ClearBackground({ 0,0,0 });

		// dibujo paleta de los jugadores
		DrawRectangle(jugador1.posicion.x, jugador1.posicion.y, jugador1.largoAlto.x, jugador1.largoAlto.y, jugador1.color);
		DrawRectangle(jugador2.posicion.x, jugador2.posicion.y, jugador2.largoAlto.x, jugador2.largoAlto.y, jugador2.color);

		// dibujo de la pelota
		DrawCircle(posicionPelota.x, posicionPelota.y, 15, { 255,0,0,255 });

		// dibujo de los puntajes
		DrawText(TextFormat("Puntaje jugador 1: %i", jugador1.puntaje), 10, 10, 20, { 255,255,255,255 });
		DrawText(TextFormat("Puntaje jugador 2: %i", jugador2.puntaje), 10, 40, 20, { 255,255,255,255 });

		EndDrawing();
	}
	CloseWindow();

	return 0;
}