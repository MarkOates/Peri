
#include <gtest/gtest.h>

#include <Peri/PieceRenderer.hpp>

TEST(Peri_PieceRendererTest, can_be_created_without_blowing_up)
{
   Peri::PieceRenderer piece_renderer;
}

TEST(Peri_PieceRendererTest, run__returns_the_expected_response)
{
   Peri::PieceRenderer piece_renderer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, piece_renderer.run());
}
