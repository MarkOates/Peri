

#include <Peri/PieceRenderer.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro_flare/placement2d.h>
#include <Peri/JellyRenderer.hpp>
#include <stdexcept>
#include <sstream>


namespace Peri
{


PieceRenderer::PieceRenderer(Peri::Piece* piece, float cell_size)
   : piece(piece)
   , cell_size(cell_size)
{
}


PieceRenderer::~PieceRenderer()
{
}


void PieceRenderer::render()
{
   if (!(piece))
      {
         std::stringstream error_message;
         error_message << "PieceRenderer" << "::" << "render" << ": error: " << "guard \"piece\" not met";
         throw std::runtime_error(error_message.str());
      }
   allegro_flare::placement2d place(piece->get_grid_x() * cell_size, piece->get_grid_y() * cell_size, 0, 0);
   float h_cell_size = cell_size * 0.5f;

   place.start_transform();

   // render jelly 1
   Peri::JellyRenderer jelly1_renderer(h_cell_size, h_cell_size, cell_size, &piece->get_jelly_1_ref());
   jelly1_renderer.render();

   // render jelly 2
   Peri::JellyRenderer jelly2_renderer(cell_size + h_cell_size, h_cell_size, cell_size, &piece->get_jelly_2_ref());
   jelly2_renderer.render();

   place.restore_transform();

   return;
}
} // namespace Peri


