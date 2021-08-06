#pragma once


#include <Peri/Jelly.hpp>


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
   };
}



