

#include <Peri/BoardRenderer.hpp>
#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro_flare/placement2d.h>
#include <Peri/Jelly.hpp>
#include <Peri/JellyRenderer.hpp>
#include <Peri/PieceRenderer.hpp>
#include <stdexcept>
#include <sstream>


namespace Peri
{


BoardRenderer::BoardRenderer(Peri::Board* board, Peri::Piece* player_piece)
   : board(board)
   , player_piece(player_piece)
   , background_color(ALLEGRO_COLOR{0.2f, 0.2f, 0.2f, 0.2f})
   , x(0)
   , y(0)
   , cell_size(100.0f)
{
}


BoardRenderer::~BoardRenderer()
{
}


void BoardRenderer::set_x(float x)
{
   this->x = x;
}


void BoardRenderer::set_y(float y)
{
   this->y = y;
}


void BoardRenderer::set_cell_size(float cell_size)
{
   this->cell_size = cell_size;
}


float BoardRenderer::get_x()
{
   return x;
}


float BoardRenderer::get_y()
{
   return y;
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
   float board_real_width = board->get_width() * cell_size;
   float board_real_height = board->get_height() * cell_size;
   allegro_flare::placement2d place(x, y, board_real_width, board_real_height);
   std::vector<Peri::Jelly*> &grid = board->get_grid_ref();
   int num_rows = board->get_height();
   int num_columns = board->get_width();
   ALLEGRO_COLOR cell_outline_color = al_color_name("pink");
   float cell_outline_thickness = 3;
   float cell_h_size = cell_size * 0.5f;

   place.start_transform();

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
         if (jelly != nullptr)
         {
            Peri::JellyRenderer jelly_renderer(
               x * cell_size + cell_h_size,
               y * cell_size + cell_h_size,
               cell_size,
               jelly);
            jelly_renderer.render();
         }
      }

   if (player_piece)
   {
      Peri::PieceRenderer piece_renderer(player_piece, cell_size);
      piece_renderer.render();
   }

   place.restore_transform();
   return;
}

void BoardRenderer::set_position(float x, float y)
{
   this->x = x;
   this->y = y;
   return;
}
} // namespace Peri


