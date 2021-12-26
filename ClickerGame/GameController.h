#pragma once
#include "CoreGame.h"
#include "Menu.h"
#include "Statistics.h"

#include <vector>
#include <algorithm>

#include <SDL_mixer.h>

class GameController//������� ����������
{
	static GameController* singleton;
	GameController(SDL_Renderer* main_renderer, int screen_width, int screen_height);//�����������

	Window* game;

	int screen_width;
	int screen_height;

	SDL_Renderer* main_renderer;
	Mix_Music* gMusic;//������ �� ������ ����

	bool is_sound;

public:
	static GameController* get_singleton(SDL_Renderer* main_renderer, int screen_width, int screen_height);//�������� ����� �����

	static GameController* get_singleton();

	void go_to_game();//������� � ����

	void go_to_menu();//������� � ����

	void go_to_statistics();//������� � ����������

	int get_screen_height();//������� ��� �������� ������

	int get_screen_width();

	bool process_input();//��������� �����

	void close();//������������ ������

	void update_scores(int score);//���������� ������ �����������

	std::vector<int> load_best_scores();//�������� ������ �����������

	bool is_sound_getter();//������ ��� ��������

	void is_sound_setter(bool value);//������ ��� ��������

	void load_is_sound();//�������� ��������

	void save_is_sound();//���������� ��������
};

