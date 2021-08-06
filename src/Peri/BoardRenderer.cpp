

#include <Peri/BoardRenderer.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro_flare/placement2d.h>
#include <Peri/Jelly.hpp>
#include <Peri/JellyRenderer.hpp>
#include <stdexcept>
#include <sstream>


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
   if (!(board))
      {
         std::stringstream error_message;
         error_message << "BoardRenderer" << "::" << "render" << ": error: " << "guard \"board\" not met";
         throw std::runtime_error(error_message.str());
      }
   allegro_flare::placement2d place;
   std::vector<Peri::Jelly*> &grid = board->get_grid_ref();

   place.start_transform();

   int num_rows = board->get_height();
   int num_columns = board->get_width();
   return;
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

   for (unsigned y=0; y<num_rows; y++)
      for (unsigned x=0; x<num_columns; x++)
      {
         Peri::Jelly *jelly = board->get_jelly_at(x, y);
         if (jelly != nullptr) Peri::JellyRenderer jelly_renderer(x * cell_size, y * cell_size, jelly);
      }

   place.restore_transform();
   return;
}
} // namespace Peri


