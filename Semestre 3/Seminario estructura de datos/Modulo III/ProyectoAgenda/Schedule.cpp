#include "Schedule.h"


/*********************************************************************
* Comment
*********************************************************************/
string Schedule::getID()
{
  return this->ID;
}
/*********************************************************************
* Comment
*********************************************************************/
string Schedule::getName()
{
  return this->Name;
}
/*********************************************************************
* Comment
*********************************************************************/
string Schedule::getDirection()
{
  return this->Direction;
}
/*********************************************************************
* Comment
*********************************************************************/
string Schedule::getNumber()
{
  return this->CellNumber;
}
/*********************************************************************
* Comment
*********************************************************************/
string Schedule::getMail()
{
  return this->Mail;
}
/*********************************************************************
* Comment
*********************************************************************/
void Schedule::setID(const string& Id)
{
  this->ID=Id;
}
/*********************************************************************
* Comment
*********************************************************************/
void Schedule::setName(const string& Name)
{
  this->Name = Name;
}
/*********************************************************************
* Comment
*********************************************************************/
void Schedule::setDirection(const string& Direction)
{
  this->Direction = Direction;
}
/*********************************************************************
* Comment
*********************************************************************/
void Schedule::setNumber(const string& Number)
{
  this->CellNumber = Number;
}
/*********************************************************************
* Comment
*********************************************************************/
void Schedule::setMail(const string& Mail)
{
  this->Mail = Mail;
}
/*********************************************************************
* Comment
*********************************************************************/
string Schedule::toString()
{
  string result;

  result="\t";
  result+=this->ID;
  result+=" || ";
  result+=this->Name;
  result+=" || ";
  result+=this->Direction;
  result+=" || ";
  result+=this->CellNumber;
  result+=" || ";
  result+=this->Mail;

  return result;
}

bool Schedule::operator != (const Schedule& s) const
{
    return this->ID != s.ID;
}
