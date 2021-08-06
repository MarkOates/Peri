

#include <Peri/BoardRenderer.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro_flare/placement2d.h>


namespace Peri
{


BoardRenderer::BoardRenderer(Peri::Board* board)
   : board(board)
   , background_color(ALLEGRO_COLOR{0.2f, 0.2f, 0.2f, 0.2f})
   , cell_size(50.0f)
{
}


BoardRenderer::~BoardRenderer()
{
}


float BoardRenderer::get_cell_size()
{
   return cell_size;
}


void BoardRenderer::render()
{
   allegro_flare::placement2d place;
   place.start_transform();

   int num_rows = board->get_height();
   int num_columns = board->get_width();
   ALLEGRO_COLOR cell_outline_color = al_color_name("pink");
   float cell_outline_thickness = 3;

   for (unsigned y=0; y<num_rows; y++)
      for (unsigned x=0; x<num_columns; x++)
      {
         al_draw_rectangle(
            x * cell_size,
            y * cell_size,
            x * cell_size + cell_size,
            y * cell_size + cell_size,
            cell_outline_color,
            cell_outline_thickness
         );
      }

   place.restore_transform();
   return;
}
} // namespace Peri


