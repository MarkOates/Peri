

#include <Peri/GameplayScreen.hpp>
#include <Peri/BoardRenderer.hpp>
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
   Peri::BoardRenderer board_renderer(&board);
   board_renderer.set_position(1920/2, 1080/2);
   board_renderer.set_cell_size(50.0f);
   board_renderer.render();
   return;
}

void GameplayScreen::key_down_func(ALLEGRO_EVENT* ev)
{
   switch(ev->keyboard.keycode)
   {
   case ALLEGRO_KEY_RIGHT:
      std::cout << "RIGHT" << std::endl;
      //framework->shutdown_program = true;
      break;
   case ALLEGRO_KEY_LEFT:
      //framework->shutdown_program = true;
      break;
   case ALLEGRO_KEY_SPACE:
      //framework->shutdown_program = true;
      break;
   case ALLEGRO_KEY_ENTER:
      //framework->shutdown_program = true;
      break;
   }
   return;
}

void GameplayScreen::generate_piece()
{
   if (current_piece) delete current_piece;
   current_piece = new Peri::Piece;
}
} // namespace Peri


