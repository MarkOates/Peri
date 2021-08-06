#pragma once


#include <Peri/Jelly.hpp>
#include <Peri/Piece.hpp>
#include <vector>


namespace Peri
{
   class Board
   {
   private:
      int width;
      int height;
      std::vector<Peri::Jelly*> grid;

   public:
      Board();
      ~Board();

      int get_width();
      int get_height();
      std::vector<Peri::Jelly*> get_grid();
      std::vector<Peri::Jelly*> &get_grid_ref();
      bool place_jelly(int x=0, int y=0, Peri::Jelly* jelly={});
      Peri::Jelly* get_jelly_at(int x=0, int y=0);
   };
}



