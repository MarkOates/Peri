

#include <Peri/Piece.hpp>



namespace Peri
{


Piece::Piece()
   : x(0.0)
   , y(0.0)
   , jelly_1({})
   , jelly_2({})
{
}


Piece::~Piece()
{
}


void Piece::set_x(float x)
{
   this->x = x;
}


void Piece::set_y(float y)
{
   this->y = y;
}


void Piece::set_jelly_1(Peri::Jelly jelly_1)
{
   this->jelly_1 = jelly_1;
}


void Piece::set_jelly_2(Peri::Jelly jelly_2)
{
   this->jelly_2 = jelly_2;
}


float Piece::get_x()
{
   return x;
}


float Piece::get_y()
{
   return y;
}


Peri::Jelly Piece::get_jelly_1()
{
   return jelly_1;
}


Peri::Jelly Piece::get_jelly_2()
{
   return jelly_2;
}


std::string Piece::run()
{
   return "Hello World!";
}
} // namespace Peri


