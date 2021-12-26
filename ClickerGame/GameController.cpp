#include "GameController.h"

GameController* GameController::singleton = nullptr;

GameController* GameController::get_singleton(SDL_Renderer* main_renderer, int screen_width, int screen_height)//��������� ������������ ����������
{
	if (singleton == nullptr)
		singleton = new GameController(main_renderer, screen_width, screen_height);

	return singleton;
}

bool GameController::process_input()//��������� ������������ ����������
{
	return game->process_input();
}

void GameController::close()
{
	//������������ ������
	Mix_FreeMusic(gMusic);
	game->close();
}

//�������� ������ �����������
std::vector<int> GameController::load_best_scores()
{
	std::vector<int> best_scores;

	//��������� ����
	SDL_RWops* file = SDL_RWFromFile("scores.bin", "r+b");

	//���� ���� �� �������
	if (file == 0)
	{
		//������� ��� � ��������� ������
		SDL_RWops* new_file = SDL_RWFromFile("scores.bin", "w+b");
		for (int i = 0; i < 10; ++i)
		{
			best_scores.push_back(0);
			SDL_RWwrite(new_file, &best_scores[i], sizeof(int), 1);
		}

		SDL_RWclose(new_file);

		return best_scores;
	}

	//����� ��������� �������� � ����
	int tmp_value;
	for (int i = 0; i < 10; ++i)
	{
		SDL_RWread(file, &tmp_value, sizeof(int), 1);
		best_scores.push_back(tmp_value);
	}

	SDL_RWclose(file);//��������� ����

	return best_scores;
}

//������ � ������ ��� �������� �����
bool GameController::is_sound_getter()
{
	return is_sound;
}

void GameController::is_sound_setter(bool value)
{
	is_sound = value;

	save_is_sound();//���������� ��������

	if (value)//���� ����� ������� ����
	{
		if (Mix_PausedMusic())
			Mix_ResumeMusic();//�� ��������
		else
			Mix_PlayMusic(gMusic, -1);
	}
	else
		Mix_PauseMusic();//����� �������������
}

//�������� ��������
void GameController::load_is_sound()
{
	SDL_RWops* file = SDL_RWFromFile("sound_settings.bin", "r+b");

	if (file == 0)
	{
		is_sound = true;
		SDL_RWops* new_file = SDL_RWFromFile("sound_settings.bin", "w+b");
		SDL_RWwrite(new_file, &is_sound, sizeof(bool), 1);

		SDL_RWclose(new_file);

		return;
	}

	SDL_RWread(file, &is_sound, sizeof(bool), 1);

	SDL_RWclose(file);
}

//cj[hfytybt yfcnhjtr
void GameController::save_is_sound()
{
	SDL_RWops* file = SDL_RWFromFile("sound_settings.bin", "w+b");

	SDL_RWwrite(file, &is_sound, sizeof(bool), 1);

	SDL_RWclose(file);
}

//���������� ������ �����������
void GameController::update_scores(int score)
{
	auto scores = load_best_scores();

	std::sort(scores.begin(), scores.end());
	std::reverse(scores.begin(), scores.end());

	if (score > scores[scores.size() - 1])
	{
		scores.erase(scores.end() - 1, scores.end());
		scores.push_back(score);

		std::sort(scores.begin(), scores.end());
		std::reverse(scores.begin(), scores.end());
	}

	SDL_RWops* file = SDL_RWFromFile("scores.bin", "w+b");

	for (int i = 0; i < 10; ++i)
		SDL_RWwrite(file, &scores[i], sizeof(int), 1);

	SDL_RWclose(file);
}

GameController* GameController::get_singleton()
{
	return singleton;
}

void GameController::go_to_game()//������� � ����
{
	game->close();
	game = new CoreGame(main_renderer, screen_width, screen_height);
}

void GameController::go_to_menu()//������� � ����
{
	game->close();
	game = new Menu(main_renderer, screen_width, screen_height);
}

void GameController::go_to_statistics()//������� � ����������
{
	game->close();
	game = new Statistics(main_renderer, screen_width, screen_height);
}

GameController::GameController(SDL_Renderer* main_renderer, int screen_width, int screen_height)
	: screen_width(screen_width), screen_height(screen_height), main_renderer(main_renderer)
{
	//��������� ������ �������� 

	load_is_sound();

	gMusic = Mix_LoadMUS("sounds/back_music.wav");

	if (is_sound && Mix_PlayingMusic() == 0)
		Mix_PlayMusic(gMusic, -1);

	game = new Menu(main_renderer, screen_width, screen_height);
}

