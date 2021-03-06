

#include <Peri/ScreenManager.hpp>
#include <Peri/GameplayScreen.hpp>


namespace Peri
{


ScreenManager::ScreenManager(AllegroFlare::Display* display, AllegroFlare::Framework* framework, AllegroFlare::Screens* screens, std::map<std::string, Peri::AudioRepositoryElement> music_track_elements, std::map<std::string, Peri::AudioRepositoryElement> sound_effect_elements)
   : AllegroFlare::Screen({})
   , display(display)
   , framework(framework)
   , screens(screens)
   , music_track_elements(music_track_elements)
   , sound_effect_elements(sound_effect_elements)
   , current_active_screen(nullptr)
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
   if (current_active_screen != nullptr)
   {
      // remove screen from screens
      screens->remove(current_active_screen);
      delete current_active_screen;
      current_active_screen = nullptr;
   }

   current_active_screen = new Peri::GameplayScreen(display);

   screens->add(current_active_screen);

   return;
}
} // namespace Peri


