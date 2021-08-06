

#include <Peri/JellyRenderer.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro_flare/placement2d.h>


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
   al_draw_filled_circle(0, 0, 20.0, al_color_name("pink"));
   place.restore_transform();

   return;
}
} // namespace Peri


