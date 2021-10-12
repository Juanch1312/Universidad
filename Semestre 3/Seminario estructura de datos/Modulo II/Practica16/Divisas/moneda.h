#ifndef MONEDA_H
# define MONEDA_H

class Moneda{
private:
  double value;
public:
  void SetValue(double);
  double GetValue();
};
/*********************************************************************
* Comment
*********************************************************************/
void Moneda::SetValue(double value)
{
  this->value = value;
}
/*********************************************************************
* Comment
*********************************************************************/
double Moneda::GetValue()
{
  return this->value;
}
#endif
