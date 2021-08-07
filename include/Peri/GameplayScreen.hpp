#pragma once


#include <AllegroFlare/Display.hpp>
#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screen.hpp>
#include <Peri/Board.hpp>
#include <Peri/Jelly.hpp>
#include <Peri/Piece.hpp>
#include <allegro5/allegro.h>


namespace Peri
{
   class GameplayScreen : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Display* display;
      AllegroFlare::Framework* framework;
      Peri::Board board;
      Peri::Piece* current_piece;

   public:
      GameplayScreen(AllegroFlare::Display* display=nullptr, AllegroFlare::Framework* framework=nullptr);
      virtual ~GameplayScreen();

      virtual void primary_timer_func() override;
      virtual void user_event_func(ALLEGRO_EVENT* ev=nullptr) override;
      void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
      void spawn_random_piece();
      float get_board_cell_width();
      void move_piece_right();
      void move_piece_left();
      void move_piece_down();
      void place_piece();
      Peri::Jelly __generate_random_jelly();
   };
}



