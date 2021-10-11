#ifndef FECHA_H_INCLIUDED
#define FECHA_H_INCLIUDED

#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

class Fecha{
private:
  int year;
  int month;
  int day;
public:
  int getYear();
  int getMonth();
  int getDay();

  void setYear(const int&);
  void setMonth(const int&);
  void setDay(const int&);
};

#endif
