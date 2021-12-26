#include "Button.h"

bool Button::check_positions()	//��������� �� ����� �� �����������
{
	int x, y;
	SDL_GetMouseState(&x, &y);//�������� ���������� �����

	return img.get_position_x() <= x && img.get_position_x() + img.get_width() >= x//� ��������� �� ����������� �� ���
		&& img.get_position_y() <= y && img.get_position_y() + img.get_height() >= y;
}

void Button::load_from_file(std::string file_name, SDL_Renderer* main_renderer)//�������� ����������� � ��������
{
	img.load_from_file(file_name, main_renderer);//������ � �����
}

void Button::load_from_text(std::string text, std::string font_name, int font_size, SDL_Renderer* main_renderer, SDL_Color text_color)
{
	if (font != nullptr)//����������� ������
	{
		TTF_CloseFont(font);
		font = nullptr;
	}

	this->text_color = text_color;

	font = TTF_OpenFont(font_name.c_str(), font_size);//������� �����

	text_texture.load_from_text(text, font, main_renderer, text_color);//� ������ �������� � ������
}

//�������� �������
int Button::get_height()
{
	return img.get_height();
}

int Button::get_width()
{
	return img.get_width();
}

void Button::render(SDL_Renderer* main_renderer)//����� ������ �� �����
{
	img.render(main_renderer, img_pos.x, img_pos.y, img_renderer_squad);//����� ��������
	text_texture.render(main_renderer, text_pos.x, text_pos.y, text_renderer_squad);//� ������
}

//������������ ������
void Button::free()
{
	img.free();
	TTF_CloseFont(font);
	font = nullptr;
	text_texture.free();
}

//��������� ����� � ������
void Button::set_text(std::string text, SDL_Renderer* main_renderer)
{
	text_texture.load_from_text(text, font, main_renderer, text_color);
}

//����� �������
void Button::set_text_pos(int x, int y)
{
	text_pos.x = x;
	text_pos.y = y;
}

void Button::set_image_pos(int x, int y)
{
	img_pos.x = x;
	img_pos.y = y;
}

//����� �������� ��� �������
void Button::set_img_renderer_squad(SDL_Rect renderer_squad)
{
	img_renderer_squad = new SDL_Rect(renderer_squad);
}

void Button::set_text_renderer_squad(SDL_Rect renderer_squad)
{
	text_renderer_squad = new SDL_Rect(renderer_squad);
}
