

#include <Peri/GameplayScreen.hpp>
#include <Peri/BoardRenderer.hpp>


namespace Peri
{


GameplayScreen::GameplayScreen(AllegroFlare::Framework* framework)
   : AllegroFlare::Screen({})
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
   Peri::BoardRenderer board_renderer(&board);
   board_renderer.render();
   std::cout << "AAA" << std::endl;
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

