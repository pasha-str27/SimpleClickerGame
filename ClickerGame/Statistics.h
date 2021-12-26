#pragma once
#include "Window.h"
#include "GameController.h"

class Statistics : public Window//окно статистики
{
	Button close_button;//обекти на екране
	Button label;

	Button score_labels[10];

public:
	Statistics(SDL_Renderer* main_renderer, int screen_width, int screen_height);

	void close() override;//освобождение памяти
	bool process_input() override;//обработка ввода
};