
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, expected_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { ASSERT_EQ(std::string(expected_exception_message), err.what()); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <Testing/WithAllegroRenderingFixture.hpp>

class Peri_TitleScreenTestWithEmptyFixture : public ::testing::Test
{};

class Peri_TitleScreenTestWithAllegroRenderingFixture
   : public Testing::WithAllegroRenderingFixture
{};


#include <Peri/TitleScreen.hpp>


TEST_F(Peri_TitleScreenTestWithEmptyFixture, can_be_created_without_blowing_up)
{
   Peri::TitleScreen title_screen;
}

TEST_F(Peri_TitleScreenTestWithEmptyFixture, primary_timer_func__without_a_display__raises_an_exception)
{
   Peri::TitleScreen title_screen;
   std::string expected_error_message = "TitleScreen::primary_timer_func: error: guard \"display\" not met";
   ASSERT_THROW_WITH_MESSAGE(title_screen.primary_timer_func(), std::runtime_error, expected_error_message);
}

TEST_F(Peri_TitleScreenTestWithAllegroRenderingFixture, render__renders_the_board)
{
   ////AllegroFlare::Display *display = al_create_display(1920, 1080);
   //Peri::Board board;
   //Peri::BoardRenderer board_renderer(&board);
   //board_renderer.render();
   //al_flip_display();
}

