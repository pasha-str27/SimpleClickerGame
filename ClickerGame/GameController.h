#pragma once
#include "CoreGame.h"
#include "Menu.h"
#include "Statistics.h"

#include <vector>
#include <algorithm>

#include <SDL_mixer.h>

class GameController//игровой контроллер
{
	static GameController* singleton;
	GameController(SDL_Renderer* main_renderer, int screen_width, int screen_height);//конструктор

	Window* game;

	int screen_width;
	int screen_height;

	SDL_Renderer* main_renderer;
	Mix_Music* gMusic;//музика на заднем фоне

	bool is_sound;

public:
	static GameController* get_singleton(SDL_Renderer* main_renderer, int screen_width, int screen_height);//получить обект класа

	static GameController* get_singleton();

	void go_to_game();//переход в игру

	void go_to_menu();//переход в меню

	void go_to_statistics();//переход к статистике

	int get_screen_height();//геттери для размеров екрана

	int get_screen_width();

	bool process_input();//обработка ввода

	void close();//освобождение памяти

	void update_scores(int score);//обновление лучших результатов

	std::vector<int> load_best_scores();//загрузка лучших результатов

	bool is_sound_getter();//геттер для настроек

	void is_sound_setter(bool value);//сеттер для настроек

	void load_is_sound();//загрузка настроек

	void save_is_sound();//сохранение настроек
};

