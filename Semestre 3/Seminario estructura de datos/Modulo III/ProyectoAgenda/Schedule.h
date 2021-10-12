#ifndef SCHEDULE_H
# define SCHEDULE_H

#include <string.h>
#include <iostream>
#include <cstdlib>

using namespace std;

class Schedule{
private:
  string ID;
  string Name;
  string Direction;
  string CellNumber;
  string Mail;
public:
  string getID();
  string getName();
  string getDirection();
  string getNumber();
  string getMail();


  void setID(const string&);
  void setName(const string&);
  void setDirection(const string&);
  void setNumber(const string&);
  void setMail(const string&);

  string toString();


  bool operator != (const Schedule&) const;///se le agrega el const porque data[m] no es const


};

#endif
