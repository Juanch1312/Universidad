#ifndef COLLECTPRODUCTS_H_INCLUIDED
#define COLLECTPRODUCTS_H_INCLUIDED

#include "Products.h"

class Collectproducts{
private:
  Products collection[500];
  int last;
public:
  void Initial();
  int getLast();

  void Update(const char* ,const char* ,const float& , const int& ,const int& ,const int& ,const float& ,const float& ,const int&);
  void Sell(const int&, const int&);
  int ValideExistence(const char*);
  void ShowTheCollection();
  int MoreExistancie(const int&, const int&);
};

#endif
