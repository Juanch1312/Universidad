#ifndef PRODUCTS_H_INCLUIDED
# define PRODUCTS_H_INCLUIDED

#include "Fecha.h"

class Products{
private:
  Fecha date1;
  char Barcode[13];
  char Name[60];
  float Weight;
  float Price;
  float MPrice;
  int Existence;
public:
  char *getBarcode();
  char *getName();
  float getWeight();
  float getPrice();
  float getMPrice();
  int getExistence();
  Fecha getDate();

  void setBarcode(const char*);
  void setName(const char*);
  void setWeight(const float&);
  void setDate(const int&,const int&, const int&);
  void setPrice(const float&);
  void setMPrice(const float&);
  void setExistence(const int&);
};

#endif
