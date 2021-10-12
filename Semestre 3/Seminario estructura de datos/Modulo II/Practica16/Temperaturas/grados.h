#ifndef GRADOS_H
# define GRADOS_H

class Grados{
private:
  double temperatura;
public:
  void SetTemperatura(double value);
  double GetTemperatura();
};
/*********************************************************************
* Comment
*********************************************************************/
void Grados::SetTemperatura(double value)
{
  this->temperatura=value;
}
/*********************************************************************
* Comment
*********************************************************************/
double Grados::GetTemperatura()
{
  return this->temperatura;
}

#endif
