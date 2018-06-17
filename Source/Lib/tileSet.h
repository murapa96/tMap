#ifndef _TILESET_
#define _TILESET_
#include <cstdlib>
#include <ctime>
#include "defineMap.h"

class tileSet{
	public:
		tileSet(int seed);
		void rotate();
		void setValue(int x, int y, int value);
		int _TILESET[TILEX][TILEY];
};
#endif
