#pragma once


#include <Peri/Jelly.hpp>
#include <allegro5/allegro.h>


namespace Peri
{
   class JellyRenderer
   {
   private:
      float x;
      float y;
      Peri::Jelly* jelly;

   public:
      JellyRenderer(float x=0.0f, float y=0.0f, Peri::Jelly* jelly=nullptr);
      ~JellyRenderer();

      void render();
      ALLEGRO_COLOR calc_jelly_color();
   };
}



