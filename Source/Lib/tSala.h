#ifndef T_SALA
#define T_SALA
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "defineMap.h"
class tSala {
public:
	tileSet tileMap;
	int id;
	int seed;
	bool norte=true, oeste=true, sur=true, este=true; 
	tSala();
	tSala(int seed);
    void printTileSet();
    bool operator!();
    bool isSala();
    
    
};
#endif // !T_SALA

