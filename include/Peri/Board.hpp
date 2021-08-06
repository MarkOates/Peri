#pragma once


#include <Peri/Piece.hpp>
#include <vector>


namespace Peri
{
   class Board
   {
   private:
      int width;
      int height;
      std::vector<Peri::Piece*> grid;

   public:
      Board();
      ~Board();

      int get_width();
      int get_height();
      std::vector<Peri::Piece*> get_grid();
   };
}



