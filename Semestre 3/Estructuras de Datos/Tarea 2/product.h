#ifndef PRODUCT_H
# define PRODUCT_H

#include "Fecha.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Product{
private:
  string Barcode[14];
  string Name[30];
  float Weight;
  float Price;
  float MPrice;
  int Existence;
public:
  char getBarcode(char*);
  char getName(char *);
  float getWeight();
  float getPrice();
  float getMPrice();
  int getExistence();

  void setBarcode(char*&);
  void setName(char*&);
  void setWeight(const float&);
  void setPrice(const float&);
  void setMPrice(const float&);
  void setExistence(const int&);
};

#endif
