

#include <Peri/ScreenManager.hpp>



namespace Peri
{


ScreenManager::ScreenManager(AllegroFlare::Framework* framework, AllegroFlare::Screens* screens, std::map<std::string, Peri::AudioRepositoryElement> music_track_elements, std::map<std::string, Peri::AudioRepositoryElement> sound_effect_elements)
   : AllegroFlare::Screen({})
   , framework(framework)
   , screens(screens)
   , music_track_elements(music_track_elements)
   , sound_effect_elements(sound_effect_elements)
{
}


ScreenManager::~ScreenManager()
{
}


void ScreenManager::initialize()
{
   return;
}

void ScreenManager::key_down_func(ALLEGRO_EVENT* ev)
{
   switch(ev->keyboard.keycode)
   {
   case ALLEGRO_KEY_ESCAPE:
      framework->shutdown_program = true;
      break;
   }
   return;
}

std::string ScreenManager::run()
{
   return "Hello World!";
}

void ScreenManager::load_initial_screen()
{
   return;
}
} // namespace Peri


