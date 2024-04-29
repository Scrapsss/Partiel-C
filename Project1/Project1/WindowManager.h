#pragma once

SDL_Renderer* renderer;
SDL_Window* window;

int InitWindow();
int Initializer();
void ClearScreen();
SDL_Renderer* CreateRenderer(SDL_Window* window);
SDL_Window* CreateWindow();