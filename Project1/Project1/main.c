#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"
#include "setSnake.h"
#include "Movement.h"

void KeyDownCheck(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_UP:
        Up = 1;
        break;
    case SDLK_DOWN:
        Down = 1;
        break;
    case SDLK_RIGHT:
        Right = 1;
        break;
    case SDLK_LEFT:
        Left = 1;
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
    playerX += playerDx * (Right - Left);
    playerY += playerDy * (Down - Up);
}

int main()
{
	Initializer();


	while (1)
	{
		ClearScreen();

		
		SDL_Rect playerSnake = setSnake(playerX, playerY, 50, 25);
        SnakeManager();
        UpdatePos();
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}

	return 0;
}

