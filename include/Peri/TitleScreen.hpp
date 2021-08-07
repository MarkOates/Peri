#pragma once


#include <AllegroFlare/Display.hpp>
#include <AllegroFlare/Screen.hpp>


namespace Peri
{
   class TitleScreen : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Display* display;

   public:
      TitleScreen(AllegroFlare::Display* display=nullptr);
      virtual ~TitleScreen();

      virtual void primary_timer_func() override;
   };
}



