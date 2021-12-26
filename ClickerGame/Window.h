#pragma once
#include "SDL.h"
#include "Button.h"

#include "texture.h"

class Window//клас игрового окна
{
protected:
	SDL_Event events;
	int screen_width;
	int screen_height;
	SDL_Renderer *main_renderer = nullptr;
public:
	Window(int screen_width, int screen_height, SDL_Renderer* main_renderer)
		: screen_width(screen_width), screen_height(screen_height), main_renderer(main_renderer)
	{
	}

	virtual void close() = 0;//чисто виртуальние методи освобожения памяти 

	virtual bool process_input() = 0;//и обработки ввода
};