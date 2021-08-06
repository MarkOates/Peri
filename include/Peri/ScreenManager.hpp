#pragma once


#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screen.hpp>
#include <AllegroFlare/Screens.hpp>
#include <Peri/AudioRepositoryElement.hpp>
#include <allegro5/allegro.h>
#include <map>
#include <string>


namespace Peri
{
   class ScreenManager : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework* framework;
      AllegroFlare::Screens* screens;
      std::map<std::string, Peri::AudioRepositoryElement> music_track_elements;
      std::map<std::string, Peri::AudioRepositoryElement> sound_effect_elements;
      AllegroFlare::Screen* current_active_screen;

   public:
      ScreenManager(AllegroFlare::Framework* framework=nullptr, AllegroFlare::Screens* screens=nullptr, std::map<std::string, Peri::AudioRepositoryElement> music_track_elements={}, std::map<std::string, Peri::AudioRepositoryElement> sound_effect_elements={});
      ~ScreenManager();

      void initialize();
      void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
      std::string run();
      void load_initial_screen();
   };
}



