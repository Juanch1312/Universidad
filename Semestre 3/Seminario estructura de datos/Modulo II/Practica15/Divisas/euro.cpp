#include "Euro.h"


/*********************************************************************
* Comment
*********************************************************************/
void Euro::setValue(double v)
{
  this->value=v;
}
/*********************************************************************
* Comment
*********************************************************************/
double Euro::getEuroPeso()
{
  return (this->value*20.1);
}
