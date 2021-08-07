#pragma once


#include <AllegroFlare/Display.hpp>
#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screens.hpp>
#include <gtest/gtest.h>


namespace Testing
{
   class WithAllegroFlareFrameworkFixture : public ::testing::Test
   {
   private:
      AllegroFlare::Display* display;
      AllegroFlare::Screens screens;
      AllegroFlare::Framework framework;

   public:
      WithAllegroFlareFrameworkFixture();
      virtual ~WithAllegroFlareFrameworkFixture();

      AllegroFlare::Display* get_display();
      AllegroFlare::Screens &get_screens_ref();
      AllegroFlare::Framework &get_framework_ref();
      virtual void SetUp() override;
      virtual void TearDown() override;
   };
}



