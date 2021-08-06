#pragma once


#include <string>


namespace Peri
{
   class Piece
   {
   private:
      float x;
      float y;
      int color_1;
      int color_2;

   public:
      Piece();
      ~Piece();

      void set_x(float x);
      void set_y(float y);
      void set_color_1(int color_1);
      void set_color_2(int color_2);
      float get_x();
      float get_y();
      int get_color_1();
      int get_color_2();
      std::string run();
   };
}



