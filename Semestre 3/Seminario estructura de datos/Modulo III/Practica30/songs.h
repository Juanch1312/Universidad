#ifndef SONGS_H
# define SONGS_H
#include <string>
#include <string.h>
using namespace std;

class Songs{
private:
  string namesong;
  string author;
  string Type;
  string Album;
  string ID;

public:

  void SetNamesong(const string);
  void SetAuthor(const string);
  void SetID(const string);
  void SetType(const string);
  void SetAlbum(const string);

  string GetNameSong();
  string GetAuthor();
  string GetID();
  string GetType();
  string GetAlbum();

  string ToStringNameSong() const;
  string ToStringAll() const;


  bool operator == (const Songs&) const;
  bool operator != (const Songs&) const;
  bool operator < (const Songs&) const;
  bool operator <= (const Songs&) const;
  bool operator > (const Songs&) const;
  bool operator >= (const Songs&) const;
};

#endif
