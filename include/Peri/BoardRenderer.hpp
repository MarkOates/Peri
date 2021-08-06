#pragma once


#include <Peri/Board.hpp>
#include <allegro5/allegro_color.h>


namespace Peri
{
   class BoardRenderer
   {
   private:
      Peri::Board* board;
      ALLEGRO_COLOR background_color;
      float cell_size;

   public:
      BoardRenderer(Peri::Board* board=nullptr);
      ~BoardRenderer();

      float get_cell_size();
      void render();
   };
}



