

#include <Peri/Jelly.hpp>



namespace Peri
{


Jelly::Jelly(int type)
   : type(type)
{
}


Jelly::~Jelly()
{
}


int Jelly::get_type()
{
   return type;
}


} // namespace Peri


