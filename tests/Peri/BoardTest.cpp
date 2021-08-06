
#include <gtest/gtest.h>

#include <Peri/Board.hpp>

TEST(Peri_BoardTest, can_be_created_without_blowing_up)
{
   Peri::Board board;
}

TEST(Peri_BoardTest, width__initializes_with_a_value_of_6)
{
   Peri::Board board;
   EXPECT_EQ(6, board.get_width());
}

TEST(Peri_BoardTest, height__initializes_with_a_value_of_12)
{
   Peri::Board board;
   EXPECT_EQ(12, board.get_height());
}

TEST(Peri_BoardTest, grid__has_a_size_of_width_times_height)
{
   Peri::Board board;
   std::vector<Peri::Piece*> grid = board.get_grid();
   int grid_length = grid.size();
   EXPECT_EQ(72, grid_length);
}

TEST(Peri_BoardTest, grid__initializes_all_elements_as_nullptr)
{
   Peri::Board board;
   std::vector<Peri::Piece*> grid = board.get_grid();
   unsigned grid_length = grid.size();
   for (unsigned i=0; i<grid_length; i++)
   {
      EXPECT_EQ(nullptr, grid[i]);
   }
}

