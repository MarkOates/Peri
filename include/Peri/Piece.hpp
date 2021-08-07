#pragma once


#include <Peri/Jelly.hpp>


namespace Peri
{
   class Piece
   {
   private:
      float grid_x;
      float grid_y;
      Peri::Jelly jelly_1;
      Peri::Jelly jelly_2;

   public:
      Piece(float grid_x=0.0, float grid_y=0.0, Peri::Jelly jelly_1={}, Peri::Jelly jelly_2={});
      ~Piece();

      void set_grid_x(float grid_x);
      void set_grid_y(float grid_y);
      void set_jelly_1(Peri::Jelly jelly_1);
      void set_jelly_2(Peri::Jelly jelly_2);
      float get_grid_x();
      float get_grid_y();
      Peri::Jelly get_jelly_1();
      Peri::Jelly get_jelly_2();
      Peri::Jelly &get_jelly_1_ref();
      Peri::Jelly &get_jelly_2_ref();
   };
}



