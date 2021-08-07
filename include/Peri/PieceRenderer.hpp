#pragma once


#include <Peri/Piece.hpp>


namespace Peri
{
   class PieceRenderer
   {
   private:
      Peri::Piece* piece;
      float cell_size;

   public:
      PieceRenderer(Peri::Piece* piece=nullptr, float cell_size=100.0f);
      ~PieceRenderer();

      void render();
   };
}



