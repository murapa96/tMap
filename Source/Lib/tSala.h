#ifndef T_SALA
#define T_SALA
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "defineMap.h"
#include "tileSet.h"
class tSala {
public:
	tileSet *tileMap;
	int id;
	int seed;
	tSala();
	tSala(int seed);
    void printTileSet();
    bool operator!();
    bool isSala();
    
    
};
#endif // !T_SALA

