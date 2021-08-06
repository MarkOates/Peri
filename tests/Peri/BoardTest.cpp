
#include <gtest/gtest.h>

#include <Peri/Board.hpp>

TEST(Peri_BoardTest, can_be_created_without_blowing_up)
{
   Peri::Board board;
}

TEST(Peri_BoardTest, run__returns_the_expected_response)
{
   Peri::Board board;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, board.run());
}
