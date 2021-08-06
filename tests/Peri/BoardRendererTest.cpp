
#include <gtest/gtest.h>

#include <Peri/BoardRenderer.hpp>

TEST(Peri_BoardRendererTest, can_be_created_without_blowing_up)
{
   Peri::BoardRenderer board_renderer;
}

TEST(Peri_BoardRendererTest, render__renders_the_board)
{
   // skip
}

TEST(Peri_BoardRendererTest, cell_size__defaults_to_50)
{
   Peri::BoardRenderer board_renderer;
   EXPECT_EQ(50.0f, board_renderer.get_cell_size());
}
