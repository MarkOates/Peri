

#include <Peri/TitleScreen.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <stdexcept>
#include <sstream>


namespace Peri
{


TitleScreen::TitleScreen(AllegroFlare::Display* display)
   : AllegroFlare::Screen({display})
   , display(display)
{
}


TitleScreen::~TitleScreen()
{
}


void TitleScreen::primary_timer_func()
{
   if (!(display))
      {
         std::stringstream error_message;
         error_message << "TitleScreen" << "::" << "primary_timer_func" << ": error: " << "guard \"display\" not met";
         throw std::runtime_error(error_message.str());
      }
   al_clear_to_color(al_color_name("violet"));
   return;
}
} // namespace Peri


