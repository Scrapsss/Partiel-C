#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"
#include "setSnake.h"

// Déclaration de la position du joueur
int playerX = 100;
int playerY = 300;

// Déclaration de la vitesse du joueur
int playerDx = 50;
int playerDy = 50;

int Up = 0;
int Down = 0;
int Left = 0;
int Right = 0;

Snake[50];

void KeyDownCheck(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_UP:
        Up = 1;
        Down = 0;
        Left = 0;
        Right = 0;
        break;
    case SDLK_DOWN:
        Up = 0;
        Down = 1;
        Left = 0;
        Right = 0;
        break;
    case SDLK_RIGHT:
        Up = 0;
        Down = 0;
        Left = 0;
        Right = 1;
        break;
    case SDLK_LEFT:
        Up = 0;
        Down = 0;
        Left = 1;
        Right = 0;
        break;
    }
}

void SnakeManager()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            KeyDownCheck(event);
            break;
        }
    }
}

void UpdatePos()
{
    if (playerY <= 0)
    {
        Up = 0;
    }
    else if (playerY + 50 >= 600)
    {
        Down = 0;
    }

    if (playerX <= 0)
    {
        Left = 0;
    }
    else if (playerX + 50 >= 1200)
    {
        Right = 0;
    }

    playerX += playerDx * (Right - Left);
    playerY += playerDy * (Down - Up);
}

int main()
{
	Initializer();


	while (1)
	{
		ClearScreen();

		SDL_Rect playerSnake = setSnake(playerX, playerY, 50, 50);
        SnakeManager();
        UpdatePos();
        printf(sizeof(Snake));
		SDL_RenderPresent(renderer);
		SDL_Delay(100);
	}

	return 0;
}

