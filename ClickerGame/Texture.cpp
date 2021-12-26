#include "Texture.h"

Texture::Texture()
{
	_texture = NULL;
	width = 0;
	height = 0;
}

void Texture::load_from_file(std::string file, SDL_Renderer* renderer)
{
	//������������ ������
	free();

	//�������� �������� � �������� ������� ����
	SDL_Surface* surface = IMG_Load(file.c_str());
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0xFF, 0xFF));

	_texture = SDL_CreateTextureFromSurface(renderer, surface);
	width = surface->w;
	height = surface->h;
	set_blend_mode(SDL_BLENDMODE_BLEND);

	//������������ ������
	SDL_FreeSurface(surface);
}

void Texture::load_from_text(std::string text, TTF_Font* font, SDL_Renderer* renderer, SDL_Color text_color)
{
	//������������ ������
	free();

	//�������� �������� � �������� ������� ����
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), text_color);
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0xFF, 0xFF));

	_texture = SDL_CreateTextureFromSurface(renderer, surface);
	width = surface->w;
	height = surface->h;

	SDL_FreeSurface(surface);
}

void Texture::free()
{
	//���� ������� �� ������ �� ����������� ������
	if (_texture != NULL)
	{
		SDL_DestroyTexture(_texture);
		_texture = NULL;
		width = 0;
		height = 0;
	}
}

void Texture::set_blend_mode(SDL_BlendMode mode)
{
	SDL_SetTextureBlendMode(_texture, mode);
}

//���������� ��������
void Texture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* renderer_squad_param)
{
	//��������� ������� ������� ���������� ������� �������� �� ������
	renderer_squad = { x,y,width,height };

	if (renderer_squad_param != NULL)
	{
		renderer_squad.w = renderer_squad_param->w;
		renderer_squad.h = renderer_squad_param->h;
	}

	//����� �������
	pos_y = y;
	pos_x = x;

	//����� �� �����
	SDL_RenderCopy(renderer, _texture, NULL, &renderer_squad);
}

//������� ��� ����� �����
int Texture::get_position_x()
{
	return pos_x;
}

int Texture::get_position_y()
{
	return pos_y;
}

int Texture::get_height()
{
	return renderer_squad.h;
}

int Texture::get_width()
{
	return renderer_squad.w;
}

Texture::~Texture()
{
	free();//����������� ������
}
