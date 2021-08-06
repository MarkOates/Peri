
#include <gtest/gtest.h>

#include <Peri/Piece.hpp>

TEST(Peri_PieceTest, can_be_created_without_blowing_up)
{
   Peri::Piece piece;
}

TEST(Peri_PieceTest, run__returns_the_expected_response)
{
   Peri::Piece piece;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, piece.run());
}
