
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

TEST_F(Peri_TitleScreenTestWithEmptyFixture, render__without_a_screen__raises_an_exception)
{
   //Peri::BoardRenderer board_renderer;
   //std::string expected_error_message = "BoardRenderer::render: error: guard \"board\" not met";
   //ASSERT_THROW_WITH_MESSAGE(board_renderer.render(), std::runtime_error, expected_error_message);
}

TEST_F(Peri_TitleScreenTestWithAllegroRenderingFixture, render__renders_the_board)
{
   ////AllegroFlare::Display *display = al_create_display(1920, 1080);
   //Peri::Board board;
   //Peri::BoardRenderer board_renderer(&board);
   //board_renderer.render();
   //al_flip_display();
}

