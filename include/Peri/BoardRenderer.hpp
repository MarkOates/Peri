#pragma once


#include <Peri/Board.hpp>
#include <Peri/Piece.hpp>
#include <allegro5/allegro_color.h>


namespace Peri
{
   class BoardRenderer
   {
   private:
      Peri::Board* board;
      Peri::Piece* player_piece;
      ALLEGRO_COLOR background_color;
      float x;
      float y;
      float cell_size;

   public:
      BoardRenderer(Peri::Board* board=nullptr, Peri::Piece* player_piece=nullptr);
      ~BoardRenderer();

      void set_x(float x);
      void set_y(float y);
      void set_cell_size(float cell_size);
      float get_x();
      float get_y();
      float get_cell_size();
      void render();
      void set_position(float x=0, float y=0);
   };
}



