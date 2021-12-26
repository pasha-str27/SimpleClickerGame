#pragma once
#include "Window.h"
#include "GameController.h"

class Menu : public Window//����� ����
{
	Button play_button;//������ �� ������
	Button statistic_button;
	Button sound_button;
	Button exit_button;

public:
	Menu(SDL_Renderer* main_renderer, int screen_width, int screen_height);//�����������

	void close() override;//������������ ������

	bool process_input() override;//�������� �����
};