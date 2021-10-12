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
void Songs::SetType( const string Inter)
{
  this->Type=Inter;
}
/*********************************************************************
* Comment
*********************************************************************/
void Songs::SetID(const string rp)
{
  this->ID=rp;
}
/*********************************************************************
* Comment
*********************************************************************/
void Songs::SetAlbum(const string al)
{
  this->Album=al;
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
string Songs::GetType()
{
  return Type;
}
/*********************************************************************
* Comment
*********************************************************************/
string Songs::GetID()
{
  return this->ID;
}
/*********************************************************************
* Comment
*********************************************************************/
string Songs::GetAlbum()
{
  return this->Album;
}


string Songs::ToStringNameSong() const{
    return " | "+ namesong +" | ";
}
string Songs::ToStringAll() const{
    return this->ID + "| " + namesong + "| " + author + "| " + Album + "| " + Type + "|";
}



bool Songs::operator==(const Songs& n) const
{
  return ToStringNameSong() == n.ToStringNameSong();
}

bool Songs::operator!=(const Songs& n) const
{
    return ToStringNameSong() != n.ToStringNameSong();
}

bool Songs::operator<(const Songs& n) const
{
    return ToStringNameSong() < n.ToStringNameSong();
}

bool Songs::operator>(const Songs& n) const
{
  return ToStringNameSong() > n.ToStringNameSong();
}

bool Songs::operator<=(const Songs& n) const
{
    return ToStringNameSong() <= n.ToStringNameSong();
}


bool Songs::operator>=(const Songs& n) const
{
    return ToStringNameSong() >= n.ToStringNameSong();
}
