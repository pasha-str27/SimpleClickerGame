#pragma once
#include "Window.h"
#include "GameController.h"

class Statistics : public Window//���� ����������
{
	Button close_button;//������ �� ������
	Button label;

	Button score_labels[10];

public:
	Statistics(SDL_Renderer* main_renderer, int screen_width, int screen_height);

	void close() override;//������������ ������
	bool process_input() override;//��������� �����
};