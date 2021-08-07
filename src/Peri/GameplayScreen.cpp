

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
      break;
   case ALLEGRO_KEY_SPACE:
      break;
   case ALLEGRO_KEY_ENTER:
      generate_piece();
      break;
   }
   return;
}

void GameplayScreen::generate_piece()
{
   if (current_piece) delete current_piece;

   Peri::Piece *new_current_piece = new Peri::Piece(0, 0, Peri::Jelly(2), Peri::Jelly(3));
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
   current_piece->set_grid_x(current_piece_grid_x + get_board_cell_width());
   //current_piece->set_grid_x += get_board_cell_width();
}

void GameplayScreen::move_piece_left()
{
   if (!current_piece) return;
}

void GameplayScreen::move_piece_down()
{
   if (!current_piece) return;
}
} // namespace Peri


