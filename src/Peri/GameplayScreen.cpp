

#include <Peri/GameplayScreen.hpp>
#include <Peri/BoardRenderer.hpp>
#include <Peri/PieceRenderer.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro.h>
#include <stdexcept>
#include <sstream>


namespace Peri
{


GameplayScreen::GameplayScreen(AllegroFlare::Display* display, AllegroFlare::Framework* framework)
   : AllegroFlare::Screen({display})
   , display(display)
   , framework(framework)
   , board({})
   , current_piece(nullptr)
{
}


GameplayScreen::~GameplayScreen()
{
}


void GameplayScreen::primary_timer_func()
{
   if (!(display))
      {
         std::stringstream error_message;
         error_message << "GameplayScreen" << "::" << "primary_timer_func" << ": error: " << "guard \"display\" not met";
         throw std::runtime_error(error_message.str());
      }
   float cell_size = 50.0f;
   al_clear_to_color(al_color_name("black"));

   // render the board (with piece if present)
   Peri::BoardRenderer board_renderer(&board, current_piece);
   board_renderer.set_position(1920/2, 1080/2);
   board_renderer.set_cell_size(cell_size);
   board_renderer.render();

   return;
}

void GameplayScreen::key_down_func(ALLEGRO_EVENT* ev)
{
   switch(ev->keyboard.keycode)
   {
   case ALLEGRO_KEY_RIGHT:
      move_piece_right();
      break;
   case ALLEGRO_KEY_LEFT:
      move_piece_left();
      break;
   case ALLEGRO_KEY_DOWN:
      move_piece_down();
      break;
   case ALLEGRO_KEY_SPACE:
      spawn_random_piece();
      break;
   case ALLEGRO_KEY_ENTER:
      place_piece();
      break;
   }
   return;
}

void GameplayScreen::spawn_random_piece()
{
   if (current_piece) delete current_piece;

   Peri::Piece *new_current_piece = new Peri::Piece(0, 0, __generate_random_jelly(), __generate_random_jelly());
   current_piece = new_current_piece;
}

float GameplayScreen::get_board_cell_width()
{
   return 100.0f;
}

void GameplayScreen::move_piece_right()
{
   if (!current_piece) return;
   float current_piece_grid_x = current_piece->get_grid_x();
   current_piece->set_grid_x(current_piece_grid_x + 1);
}

void GameplayScreen::move_piece_left()
{
   if (!current_piece) return;
   float current_piece_grid_x = current_piece->get_grid_x();
   current_piece->set_grid_x(current_piece_grid_x - 1);
}

void GameplayScreen::move_piece_down()
{
   if (!current_piece) return;
   float current_piece_grid_y = current_piece->get_grid_y();
   current_piece->set_grid_y(current_piece_grid_y + 1);
}

void GameplayScreen::place_piece()
{
   if (!current_piece) return;
   Peri::Jelly *jelly_1 = new Peri::Jelly(current_piece->get_jelly_1());
   Peri::Jelly *jelly_2 = new Peri::Jelly(current_piece->get_jelly_2());

   board.place_jelly((int)current_piece->get_grid_x(), (int)current_piece->get_grid_y(), jelly_1);
   board.place_jelly((int)current_piece->get_grid_x() + 1, (int)current_piece->get_grid_y(), jelly_2);

   delete current_piece;
   current_piece = nullptr;
}

Peri::Jelly GameplayScreen::__generate_random_jelly()
{
   int random_jelly_type = rand() % 3;
   return Peri::Jelly(random_jelly_type);
}
} // namespace Peri


