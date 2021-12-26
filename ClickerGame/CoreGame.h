#pragma once
#include "Button.h"
#include "Window.h"
#include "GameController.h"

#include <SDL_mixer.h>

class CoreGame : public Window//клас игрового екрана
{
	Button click_object;//обекти на екране
	Button counter_text;
	Button menu_button;
	SDL_Rect click_object_pos;

	int counter = 0;//счетчик очков

	Mix_Chunk* click_sound = NULL;//звуковие ефекти
	Mix_Chunk* game_over_sound = NULL;

public:
	CoreGame(SDL_Renderer* main_renderer, int screen_width, int screen_height);

	void close() override;
	bool process_input() override;

	//Генерація випадкової позиції на екрані для текстури
	SDL_Rect generate_position(int img_height, int img_width, int screen_width, int screen_height);
};