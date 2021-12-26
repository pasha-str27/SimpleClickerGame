#include "CoreGame.h"

CoreGame::CoreGame(SDL_Renderer* main_renderer, int screen_width, int screen_height)
		: Window(screen_width, screen_height, main_renderer)
{
	//создаем текстуру
	click_object.load_from_file("images/purebackground.png", main_renderer);

	//генерируем позицию для обекта
	click_object_pos = generate_position(click_object.get_height(), click_object.get_width(), screen_width, screen_height);

	//создаем обекти на екране
	click_object.set_image_pos(click_object_pos.x, click_object_pos.y);

	counter_text.load_from_text("Score: " + std::to_string(counter), "fonts/RoughenCornerRegular-7RjV.ttf", 50, main_renderer, { 0,0,0 });
	counter_text.set_text_pos((screen_width - counter_text.get_width()) / 2 - 80, 0);

	menu_button.load_from_file("images/buttonBG.png", main_renderer);
	menu_button.load_from_text("Menu", "fonts/RoughenCornerRegular-7RjV.ttf", 30, main_renderer, { 0, 0, 0 });

	menu_button.set_img_renderer_squad({ 0, 0, 85, 40 });
	menu_button.set_text_renderer_squad({ 0, 0, 70, 30 });
	menu_button.set_image_pos(0, 10);
	menu_button.set_text_pos(8, 15);

	click_sound = Mix_LoadWAV("sounds/click.wav");//грузим звуки
	game_over_sound = Mix_LoadWAV("sounds/game_over.wav");
}

//освобождение памяти
void CoreGame::close()
{
	Mix_FreeChunk(click_sound);
	Mix_FreeChunk(game_over_sound);

	click_object.free();
	counter_text.free();
	menu_button.free();
}

//обработка ввода
bool CoreGame::process_input()
{
	while (SDL_PollEvent(&events) != 0)
	{
		if (events.type == SDL_QUIT)
			return true;

		//если нажали кнопкой миши
		if (events.type == SDL_MOUSEBUTTONUP)
		{
			//если нажали на игровой обект
			if (click_object.check_positions())
			{
				counter++;
				//генерируем новую позицию
				click_object_pos = generate_position(click_object.get_height(), click_object.get_width(), screen_width, screen_height);

				click_object.set_image_pos(click_object_pos.x, click_object_pos.y);

				//и проигриваем ефект
				if (GameController::get_singleton()->is_sound_getter())
					Mix_PlayChannel(-1, click_sound, 0);
			}
			else
			{
				//иначе проигриваем другой ефект 
				if(GameController::get_singleton()->is_sound_getter())
					Mix_PlayChannel(-1, game_over_sound, 0);

				//и обнуляем счетчик обновляя лучшие результати
				GameController::get_singleton()->update_scores(counter);
				counter = 0;
			}

			//обновляем текст
			counter_text.set_text("Score: " + std::to_string(counter), main_renderer);

			//если нажали на кнопку меню то переходим в меню
			if (menu_button.check_positions())
				GameController::get_singleton()->go_to_menu();
		}
	}

	//прорисовуем текстури
	SDL_SetRenderDrawColor(main_renderer, 0, 255, 255, 255);
	SDL_RenderClear(main_renderer);


	click_object.render(main_renderer);
	counter_text.render(main_renderer);
	menu_button.render(main_renderer);

	SDL_RenderPresent(main_renderer);
}

//генерация новой позии игрового обекта
SDL_Rect CoreGame::generate_position(int img_height, int img_width, int screen_width, int screen_height)
{
    int center_x = rand() % (screen_width - img_width) + img_width / 2;
	int center_y = rand() % (screen_height - img_height) + img_height / 2;
	
	return { center_x - img_width / 2,center_y - img_height / 2,center_x + img_width / 2,center_y + img_height / 2 };
}