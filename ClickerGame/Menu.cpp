#include "Menu.h"

Menu::Menu(SDL_Renderer* main_renderer, int screen_width, int screen_height)
	: Window(screen_width, screen_height, main_renderer)
{
	//создаем обекти на екране

	play_button.load_from_file("images/buttonBG.png", main_renderer);
	play_button.load_from_text("Play", "fonts/RoughenCornerRegular-7RjV.ttf", 50, main_renderer, { 0,0,0 });

	play_button.set_img_renderer_squad({ 0, 0, 250, 80 });
	play_button.set_image_pos(300, 200);
	play_button.set_text_pos(380, 215);

	statistic_button.load_from_file("images/buttonBG.png", main_renderer);
	statistic_button.load_from_text("Statistics", "fonts/RoughenCornerRegular-7RjV.ttf", 50, main_renderer, { 0,0,0 });

	statistic_button.set_img_renderer_squad({ 0, 0, 250, 80 });
	statistic_button.set_image_pos(300, 300);
	statistic_button.set_text_pos(320, 315);

	sound_button.load_from_file("images/buttonBG.png", main_renderer);
	sound_button.load_from_text("Sound ON", "fonts/RoughenCornerRegular-7RjV.ttf", 50, main_renderer, { 0,0,0 });

	sound_button.set_img_renderer_squad({ 0, 0, 250, 80 });
	sound_button.set_image_pos(300, 400);
	sound_button.set_text_pos(320, 415);

	exit_button.load_from_file("images/buttonBG.png", main_renderer);
	exit_button.load_from_text("Exit", "fonts/RoughenCornerRegular-7RjV.ttf", 50, main_renderer, { 0,0,0 });

	exit_button.set_img_renderer_squad({ 0, 0, 250, 80 });
	exit_button.set_image_pos(300, 500);
	exit_button.set_text_pos(380, 515);
}

//освобождаем память
void Menu::close()
{
	play_button.free();
	statistic_button.free();
	sound_button.free();
	exit_button.free();
}

bool Menu::process_input()
{
	while (SDL_PollEvent(&events) != 0)
	{
		if (events.type == SDL_QUIT)
			return true;

		if (events.type == SDL_MOUSEBUTTONUP)
		{
			if (exit_button.check_positions())
				return true;

			if (play_button.check_positions())//нажали на кнопку играть
				GameController::get_singleton()->go_to_game();//переходим в игру

			if (statistic_button.check_positions())
				GameController::get_singleton()->go_to_statistics();//переходим к статистике

			if (sound_button.check_positions())//на кнопку звука
			{
				//изменяем  значение звукових ефектов
				if(GameController::get_singleton()->is_sound_getter())
					sound_button.load_from_text("Sound OFF", "fonts/RoughenCornerRegular-7RjV.ttf", 50, main_renderer, { 0,0,0 });
				else
					sound_button.load_from_text("Sound ON", "fonts/RoughenCornerRegular-7RjV.ttf", 50, main_renderer, { 0,0,0 });
			
				GameController::get_singleton()->is_sound_setter(!GameController::get_singleton()->is_sound_getter());
			}
		}
	}

	//прорисовка обектов
	SDL_SetRenderDrawColor(main_renderer, 0, 255, 255, 255);
	SDL_RenderClear(main_renderer);

	play_button.render(main_renderer);
	statistic_button.render(main_renderer);
	sound_button.render(main_renderer);
	exit_button.render(main_renderer);

	SDL_RenderPresent(main_renderer);
}
