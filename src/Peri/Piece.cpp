

#include <Peri/Piece.hpp>



namespace Peri
{


Piece::Piece(float grid_x, float grid_y, Peri::Jelly jelly_1, Peri::Jelly jelly_2)
   : grid_x(grid_x)
   , grid_y(grid_y)
   , jelly_1(jelly_1)
   , jelly_2(jelly_2)
{
}


Piece::~Piece()
{
}


void Piece::set_grid_x(float grid_x)
{
   this->grid_x = grid_x;
}


void Piece::set_grid_y(float grid_y)
{
   this->grid_y = grid_y;
}


void Piece::set_jelly_1(Peri::Jelly jelly_1)
{
   this->jelly_1 = jelly_1;
}


void Piece::set_jelly_2(Peri::Jelly jelly_2)
{
   this->jelly_2 = jelly_2;
}


float Piece::get_grid_x()
{
   return grid_x;
}


float Piece::get_grid_y()
{
   return grid_y;
}


Peri::Jelly Piece::get_jelly_1()
{
   return jelly_1;
}


Peri::Jelly Piece::get_jelly_2()
{
   return jelly_2;
}


Peri::Jelly &Piece::get_jelly_1_ref()
{
   return jelly_1;
}


Peri::Jelly &Piece::get_jelly_2_ref()
{
   return jelly_2;
}


} // namespace Peri


