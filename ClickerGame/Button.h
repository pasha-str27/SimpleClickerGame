#pragma once
#include "SDL.h"
#include "Texture.h"

class Button//клас кнопки
{
	Texture img;//задний фон
	Texture text_texture;//текст

	TTF_Font* font;//шрифт
	SDL_Color text_color;//цвет

	SDL_Point img_pos;//позици
	SDL_Point text_pos;

	SDL_Rect* img_renderer_squad = NULL;//квадрат для рендера
	SDL_Rect* text_renderer_squad = NULL;

public:

	//находится ли мишка на изображении
	bool check_positions();

	void load_from_file(std::string file_name, SDL_Renderer *main_renderer);//создание изображения с текстури

	void load_from_text(std::string text, std::string font_name, int font_size, SDL_Renderer* main_renderer, SDL_Color text_color);//и с текста
	
	int get_height();//размери кнопки

	int get_width();

	void render(SDL_Renderer *main_renderer);//вивод кнопки на екран

	void free();//освобождение памяти

	void set_text(std::string text, SDL_Renderer* main_renderer);//обновление текста на кнопке

	//изменение позиции кнопки на екране
	void set_text_pos(int x, int y);

	void set_image_pos(int x, int y);

	void set_img_renderer_squad(SDL_Rect renderer_squad);//изменение области на екране для рендера кнопки

	void set_text_renderer_squad(SDL_Rect renderer_squad);
};

