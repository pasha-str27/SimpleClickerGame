#pragma once
#include "SDL.h"
#include "Texture.h"

class Button//���� ������
{
	Texture img;//������ ���
	Texture text_texture;//�����

	TTF_Font* font;//�����
	SDL_Color text_color;//����

	SDL_Point img_pos;//������
	SDL_Point text_pos;

	SDL_Rect* img_renderer_squad = NULL;//������� ��� �������
	SDL_Rect* text_renderer_squad = NULL;

public:

	//��������� �� ����� �� �����������
	bool check_positions();

	void load_from_file(std::string file_name, SDL_Renderer *main_renderer);//�������� ����������� � ��������

	void load_from_text(std::string text, std::string font_name, int font_size, SDL_Renderer* main_renderer, SDL_Color text_color);//� � ������
	
	int get_height();//������� ������

	int get_width();

	void render(SDL_Renderer *main_renderer);//����� ������ �� �����

	void free();//������������ ������

	void set_text(std::string text, SDL_Renderer* main_renderer);//���������� ������ �� ������

	//��������� ������� ������ �� ������
	void set_text_pos(int x, int y);

	void set_image_pos(int x, int y);

	void set_img_renderer_squad(SDL_Rect renderer_squad);//��������� ������� �� ������ ��� ������� ������

	void set_text_renderer_squad(SDL_Rect renderer_squad);
};

