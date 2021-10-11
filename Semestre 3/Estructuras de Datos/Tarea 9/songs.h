#ifndef SONGS_H
# define SONGS_H
#include <string>
#include <string.h>
using namespace std;

class Songs{
private:
  string namesong;
  string author;
  string interprete;
  string rankingpos;

public:
  void SetNamesong(const string);
  void SetAuthor(const string);
  void SetInterprete(const string);
  void SetRankingPos(const string);

  string GetNameSong();
  string GetAuthor();
  string GetInterprete();
  string GetRankingPos();

  string ToString() const;


  bool operator == (const Songs&) const;
  bool operator != (const Songs&) const;
  bool operator < (const Songs&) const;
  bool operator <= (const Songs&) const;
  bool operator > (const Songs&) const;
  bool operator >= (const Songs&) const;
};

#endif
