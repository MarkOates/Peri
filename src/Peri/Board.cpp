

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


std::vector<Peri::Piece*> Board::get_grid()
{
   return grid;
}


} // namespace Peri


