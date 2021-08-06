

#include <Peri/Board.hpp>



namespace Peri
{


Board::Board()
   : width(6)
   , height(12)
   , grid(get_width() * get_height(), nullptr)
{
}


Board::~Board()
{
}


int Board::get_width()
{
   return width;
}


int Board::get_height()
{
   return height;
}


std::vector<Peri::Jelly*> Board::get_grid()
{
   return grid;
}


std::vector<Peri::Jelly*> &Board::get_grid_ref()
{
   return grid;
}


bool Board::place_jelly(int x, int y, Peri::Jelly* jelly)
{
   if (x < 0) return false;
   if (y < 0) return false;
   if (x >= width) return false;
   if (y >= height) return false;

   grid[y * width + x] = jelly;

   return true;
}

Peri::Jelly* Board::get_jelly_at(int x, int y)
{
   if (x < 0) return nullptr;
   if (y < 0) return nullptr;
   if (x >= width) return nullptr;
   if (y >= height) return nullptr;
   return grid[y * width + x];
}
} // namespace Peri


