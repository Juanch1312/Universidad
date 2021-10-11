#ifndef SONGS_H
# define SONGS_H
#include <string>
#include <string.h>
using namespace std;

class Songs{
private:
  char namesong[50];
  char author[50];
  char interprete[50];
  int rankingpos;

public:
  void SetNamesong(const char*);
  void SetAuthor(const char*);
  void SetInterprete(const char*);
  void SetRankingPos(const int&);

  char *GetNameSong();
  char *GetAuthor();
  char *GetInterprete();
  int GetRankingPos();
};

#endif
