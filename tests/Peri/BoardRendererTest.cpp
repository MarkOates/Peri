
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, expected_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { ASSERT_EQ(std::string(expected_exception_message), err.what()); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <Testing/WithAllegroRenderingFixture.hpp>

class Peri_BoardRendererTestWithEmptyFixture : public ::testing::Test
{};

class Peri_BoardRendererTestWithAllegroRenderingFixture
   : public Testing::WithAllegroRenderingFixture
{};


#include <Peri/BoardRenderer.hpp>


TEST_F(Peri_BoardRendererTestWithEmptyFixture, can_be_created_without_blowing_up)
{
   Peri::BoardRenderer board_renderer;
}

TEST_F(Peri_BoardRendererTestWithEmptyFixture, cell_size__defaults_to_50)
{
   Peri::BoardRenderer board_renderer;
   EXPECT_EQ(50.0f, board_renderer.get_cell_size());
}

TEST_F(Peri_BoardRendererTestWithEmptyFixture, render__without_a_board__raises_an_exception)
{
   Peri::BoardRenderer board_renderer;
   std::string expected_error_message = "BoardRenderer::render: error: guard \"board\" not met";
   ASSERT_THROW_WITH_MESSAGE(board_renderer.render(), std::runtime_error, expected_error_message);
}

TEST_F(Peri_BoardRendererTestWithAllegroRenderingFixture, render__renders_the_board)
{
   Peri::Board board;
   Peri::BoardRenderer board_renderer(&board);
   board_renderer.render();
   al_flip_display();
   sleep(1);
}

