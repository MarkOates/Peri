

#include <Testing/WithAllegroFlareFrameworkFixture.hpp>
#include <allegro5/allegro.h>


namespace Testing
{


WithAllegroFlareFrameworkFixture::WithAllegroFlareFrameworkFixture()
   : ::testing::Test()
   , display(nullptr)
   , screens({})
   , framework({screens})
{
}


WithAllegroFlareFrameworkFixture::~WithAllegroFlareFrameworkFixture()
{
}


AllegroFlare::Display* &WithAllegroFlareFrameworkFixture::get_display_ref()
{
   return display;
}


AllegroFlare::Screens &WithAllegroFlareFrameworkFixture::get_screens_ref()
{
   return screens;
}


AllegroFlare::Framework &WithAllegroFlareFrameworkFixture::get_framework_ref()
{
   return framework;
}


void WithAllegroFlareFrameworkFixture::SetUp()
{
   ASSERT_EQ(false, al_is_system_installed());

   framework.initialize();
   display = framework.create_display(AllegroFlare::Display::RESOLUTION_HD_1080);

   return;
}

void WithAllegroFlareFrameworkFixture::TearDown()
{
   framework.destruct();

   //font_bin.clear();
   //al_shutdown_ttf_addon(); // NOTE: this may be required, otherwise subsequent al_init_ttf_addon will not work
                              // this is a bug in Allegro
   return;
}
} // namespace Testing


