#ifndef T_MAP
#define T_MAP
#include "tSala.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
class tMap {
public:
	tSala *pLocation;
	tMap();
	void irNorte();
	void irSur();
	void irEste();
	void irOeste();
};

#endif