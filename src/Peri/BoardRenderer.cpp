

#include <Peri/BoardRenderer.hpp>
#include <allegro5/allegro_primitives.h>


namespace Peri
{


BoardRenderer::BoardRenderer(Peri::Board* board)
   : board(board)
   , background_color(ALLEGRO_COLOR{0.2f, 0.2f, 0.2f, 0.2f})
{
}


BoardRenderer::~BoardRenderer()
{
}


void BoardRenderer::render()
{
   al_draw_filled_rectangle(0, 0, 100, 300, background_color);
   return;
}
} // namespace Peri


