
#include <gtest/gtest.h>

#include <Peri/BoardRenderer.hpp>

TEST(Peri_BoardRendererTest, can_be_created_without_blowing_up)
{
   Peri::BoardRenderer board_renderer;
}

TEST(Peri_BoardRendererTest, run__returns_the_expected_response)
{
   Peri::BoardRenderer board_renderer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, board_renderer.run());
}
