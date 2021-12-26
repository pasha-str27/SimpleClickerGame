#include "Statistics.h"

Statistics::Statistics(SDL_Renderer* main_renderer, int screen_width, int screen_height)
	: Window(screen_width, screen_height, main_renderer)
{
	//создание обектов
	close_button.load_from_file("images/buttonBG.png", main_renderer);
	close_button.load_from_text("Menu", "fonts/RoughenCornerRegular-7RjV.ttf", 50, main_renderer, { 0,0,0 });

	close_button.set_img_renderer_squad({ 0, 0, 250, 80 });
	close_button.set_image_pos(300, 630);
	close_button.set_text_pos(375, 645);

	label.load_from_text("Best scores", "fonts/RoughenCornerRegular-7RjV.ttf", 50, main_renderer, { 0,0,0 });
	label.set_text_pos(300, 115);

	auto best_scores = GameController::get_singleton()->load_best_scores();

	for (int i = 0; i < 10; ++i)
	{
		score_labels[i].load_from_text(std::to_string(i + 1) + ". " + std::to_string(best_scores[i]), "fonts/RoughenCornerRegular-7RjV.ttf", 30, main_renderer, { 0,0,0 });
		score_labels[i].set_text_pos(250, 200 + i * 40);
	}
}

void Statistics::close()
{
	//освобождение памяти
	close_button.free();
	label.free();

	for (int i = 0; i < 10; ++i)
		score_labels[i].free();
}

bool Statistics::process_input()
{
	while (SDL_PollEvent(&events) != 0)
	{
		if (events.type == SDL_QUIT)
			return true;

		if (events.type == SDL_MOUSEBUTTONUP)
		{
			if (close_button.check_positions())
				GameController::get_singleton()->go_to_menu();//переход в меню
		}
	}

	//прорисовка сцени
	SDL_SetRenderDrawColor(main_renderer, 0, 255, 255, 255);
	SDL_RenderClear(main_renderer);

	close_button.render(main_renderer);
	label.render(main_renderer);

	for (int i = 0; i < 10; ++i)
		score_labels[i].render(main_renderer);

	SDL_RenderPresent(main_renderer);
}