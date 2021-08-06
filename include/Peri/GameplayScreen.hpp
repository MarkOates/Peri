#pragma once


#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screen.hpp>
#include <Peri/Board.hpp>
#include <Peri/Piece.hpp>
#include <allegro5/allegro.h>


namespace Peri
{
   class GameplayScreen : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework* framework;
      Peri::Board board;
      Peri::Piece* current_piece;

   public:
      GameplayScreen(AllegroFlare::Framework* framework=nullptr);
      virtual ~GameplayScreen();

      virtual void primary_timer_func() override;
      void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
      void generate_piece();
   };
}



