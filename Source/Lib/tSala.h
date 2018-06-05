#ifndef T_SALA
#define T_SALA
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "defineMap.h"
class tSala {
public:
	int tileMap[TILEX][TILEY];
	int id;
	int seed;
	bool norte=true, oeste=true, sur=true, este=true; 
	tSala();
	tSala(int seed);
    void printTileSet();
    void generateTileSet();
    void generateTileSet(int seed);
    bool operator!();
    bool isSala();
    
    
};
#endif // !T_SALA

