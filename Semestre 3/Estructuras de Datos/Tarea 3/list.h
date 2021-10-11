#ifndef LIST_H
# define LIST_H

#include <iostream>
#include "songs.h"
#include "listexception.h"
#include <string>
#include <string.h>
using namespace std;

class List{
private:
  Songs ranking[50];
  int last;

  bool isValidPos(const int&);

public:
  void  initialize();

  bool isEmpty();
  bool isFull();

  void insertData(const int&,const char*,const char*,const char*,const int&);

  void deleteData(const int&);

  int getFirstPos();
  int getlastPos();
  int getPrevPos(const int&);
  int getNextPos(const int&);

  int retrieve(const int&);

  void print();

  void deleteAll();
};
#endif
