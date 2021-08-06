

#include <Peri/JellyRenderer.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro_flare/placement2d.h>
#include <allegro5/allegro_color.h>
#include <stdexcept>
#include <sstream>


namespace Peri
{


JellyRenderer::JellyRenderer(float x, float y, Peri::Jelly* jelly)
   : x(x)
   , y(y)
   , jelly(jelly)
{
}


JellyRenderer::~JellyRenderer()
{
}


void JellyRenderer::render()
{
   allegro_flare::placement2d place(x, y, 0, 0);

   place.start_transform();
   al_draw_filled_circle(0, 0, 20.0, calc_jelly_color());
   place.restore_transform();

   return;
}

ALLEGRO_COLOR JellyRenderer::calc_jelly_color()
{
   if (!(jelly))
      {
         std::stringstream error_message;
         error_message << "JellyRenderer" << "::" << "calc_jelly_color" << ": error: " << "guard \"jelly\" not met";
         throw std::runtime_error(error_message.str());
      }
   switch(jelly->get_type())
   {
   case 0: return al_color_name("gray");
   case 1: return al_color_name("red");
   case 2: return al_color_name("yellow");
   case 3: return al_color_name("blue");
   default: return al_color_name("white");
   }
}
} // namespace Peri


