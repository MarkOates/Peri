

#include <Peri/Piece.hpp>



namespace Peri
{


Piece::Piece()
   : x(0.0)
   , y(0.0)
   , color_1(0)
   , color_2(0)
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


void Piece::set_color_1(int color_1)
{
   this->color_1 = color_1;
}


void Piece::set_color_2(int color_2)
{
   this->color_2 = color_2;
}


float Piece::get_x()
{
   return x;
}


float Piece::get_y()
{
   return y;
}


int Piece::get_color_1()
{
   return color_1;
}


int Piece::get_color_2()
{
   return color_2;
}


std::string Piece::run()
{
   return "Hello World!";
}
} // namespace Peri


