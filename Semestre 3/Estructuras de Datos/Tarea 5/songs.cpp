#include "Songs.h"


/*********************************************************************
* Comment
*********************************************************************/
void Songs::SetNamesong(const string NameS)
{
  this->namesong=NameS;
}
/*********************************************************************
* Comment
*********************************************************************/
void Songs::SetAuthor(const string Auth)
{
  this->author=Auth;
}
/*********************************************************************
* Comment
*********************************************************************/
void Songs::SetInterprete( const string Inter)
{
  this->interprete=Inter;
}
/*********************************************************************
* Comment
*********************************************************************/
void Songs::SetRankingPos(const string rp)
{
  this->rankingpos=rp;
}
/*********************************************************************
* Comment
*********************************************************************/
string Songs::GetNameSong()
{
  return namesong;
}
/*********************************************************************
* Comment
*********************************************************************/
string Songs::GetAuthor()
{
  return author;
}
/*********************************************************************
* Comment
*********************************************************************/
string Songs::GetInterprete()
{
  return interprete;
}
/*********************************************************************
* Comment
*********************************************************************/
string Songs::GetRankingPos()
{
  return rankingpos;
}


string Songs::toString() const{
    return namesong + "| " + author + "| " + interprete + "| " + rankingpos;
}




bool Songs::operator==(const Songs& n) const
{
  if(this->namesong==n.namesong){
    return this->namesong==n.namesong;
  }
  else{
    if(this->author==n.author){
      return this->author==n.author;
    }
    return false;
  }
}

bool Songs::operator!=(const Songs& n) const
{
    return toString() != n.toString();
}

bool Songs::operator<(const Songs& n) const
{
    return toString() < n.toString();
}

bool Songs::operator>(const Songs& n) const
{
  return toString() > n.toString();
}

bool Songs::operator<=(const Songs& n) const
{
    return toString() <= n.toString();
}


bool Songs::operator>=(const Songs& n) const
{
    return toString() >= n.toString();
}
