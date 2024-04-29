#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"

int InitWindow()
{
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to load SDL\n");
        return -1;
    }
    return 0;
}

SDL_Renderer* CreateRenderer(SDL_Window* window)
{
    // creation du render 
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("Failed to create renderer\n");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    return renderer;
}

SDL_Window* CreateWindow()
{
    // creation de la fenêtre
    window = SDL_CreateWindow("R-Type", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 600, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Failed to create window\n");
        SDL_Quit();
        return -1;
    }
    return window;
}

// ----- Initialise toute la fenetre SDL ----- 
int Initializer()
{
    // Si l'initialisation a bien marché 
    if (InitWindow() == 0)
    {
        window = CreateWindow(); //On crée la fenêtre
        renderer = CreateRenderer(window);
    }
}

void ClearScreen()
{
    // Clear rendu + set white color 
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}