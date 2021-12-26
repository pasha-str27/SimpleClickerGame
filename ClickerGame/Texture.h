#pragma once
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>
#include <iostream>

class Texture//���� ���������
{
	SDL_Texture* _texture;//��������
	int width;//�������
	int height;
	int pos_x;//������� �� ������
	int pos_y;

	SDL_Rect renderer_squad;//������� � ������� ��������� ��������

public:
	//�����������
	Texture();

	//�������� �������� � �����
	void load_from_file(std::string file, SDL_Renderer* renderer);

	//�������� �������� � ������
	void load_from_text(std::string text, TTF_Font* font, SDL_Renderer* renderer, SDL_Color text_color);

	//������������ ������
	void free();

	//����� ����������
	void set_blend_mode(SDL_BlendMode mode);

	//������ ���������
	void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* renderer_squad_param = NULL);

	//������ �������
	int get_position_x();

	int get_position_y();

	//������� ��������
	int get_height();

	int get_width();

	//����������
	~Texture();
};