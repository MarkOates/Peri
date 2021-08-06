#pragma once


#include <Peri/Jelly.hpp>
#include <string>


namespace Peri
{
   class Piece
   {
   private:
      float x;
      float y;
      Peri::Jelly jelly_1;
      Peri::Jelly jelly_2;

   public:
      Piece();
      ~Piece();

      void set_x(float x);
      void set_y(float y);
      void set_jelly_1(Peri::Jelly jelly_1);
      void set_jelly_2(Peri::Jelly jelly_2);
      float get_x();
      float get_y();
      Peri::Jelly get_jelly_1();
      Peri::Jelly get_jelly_2();
      std::string run();
   };
}



