#pragma once
#include "Window.h"
#include "GameController.h"

class Menu : public Window//екран меню
{
	Button play_button;//обекти на екране
	Button statistic_button;
	Button sound_button;
	Button exit_button;

public:
	Menu(SDL_Renderer* main_renderer, int screen_width, int screen_height);//конструктор

	void close() override;//освобождение памяти

	bool process_input() override;//обаботка ввода
};