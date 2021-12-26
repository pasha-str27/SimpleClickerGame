#pragma once
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>
#include <iostream>

class Texture//клас текстурки
{
	SDL_Texture* _texture;//текстура
	int width;//размери
	int height;
	int pos_x;//позиция на екране
	int pos_y;

	SDL_Rect renderer_squad;//квадрат в котором рендерить текстуру

public:
	//конструктор
	Texture();

	//загрузка текстури с файла
	void load_from_file(std::string file, SDL_Renderer* renderer);

	//загрузка текстури с текста
	void load_from_text(std::string text, TTF_Font* font, SDL_Renderer* renderer, SDL_Color text_color);

	//освобождение памяти
	void free();

	//смена параметров
	void set_blend_mode(SDL_BlendMode mode);

	//рендер текстурки
	void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* renderer_squad_param = NULL);

	//позция спрайта
	int get_position_x();

	int get_position_y();

	//размери текстури
	int get_height();

	int get_width();

	//деструктор
	~Texture();
};