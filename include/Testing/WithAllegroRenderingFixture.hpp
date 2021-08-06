#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro_flare/placement2d.h>
#include <allegro_flare/placement3d.h>
#include <gtest/gtest.h>


namespace Testing
{
   class WithAllegroRenderingFixture : public ::testing::Test
   {
   private:
      ALLEGRO_DISPLAY* display;
      AllegroFlare::FontBin font_bin;

   public:
      WithAllegroRenderingFixture();
      virtual ~WithAllegroRenderingFixture();

      ALLEGRO_DISPLAY* get_display();
      AllegroFlare::FontBin &get_font_bin_ref();
      virtual void SetUp() override;
      virtual void TearDown() override;
      ALLEGRO_FONT* get_any_font();
      allegro_flare::placement3d build_centered_placement3d(float width=0.0f, float height=0.0f);
      allegro_flare::placement2d build_centered_placement2d(float width=0.0f, float height=0.0f);
   };
}



