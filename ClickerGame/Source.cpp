#include <ctime>
#include <iostream>

#include "CoreGame.h"
#include "Menu.h"

#include "GameController.h"

#define screen_height 800//размери окна
#define screen_width 800


int main(int arc, char** argv)
{
	srand(time(NULL));
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);//инизиализация SDL
	IMG_Init(IMG_INIT_PNG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	TTF_Init();

	//создаем переменние для работи програми
	SDL_Window* main_window = SDL_CreateWindow("Clicker game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	SDL_Renderer* main_renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//создаем контроллер для работи
	GameController* game_controller = GameController::get_singleton(main_renderer, screen_width, screen_height);

	//пока не закроем окно обробляем ввод пользователя и обновляем изображение на екране
	while (true)
		if (game_controller->process_input())
			break;

	//освобождаем память
	game_controller->close();
	delete game_controller;

	SDL_DestroyRenderer(main_renderer);
	SDL_DestroyWindow(main_window);
	main_renderer = NULL;
	main_window = NULL;
	SDL_Quit();
	IMG_Quit();

	return 0;
}
