#ifndef T_MAP
#define T_MAP
#define ARRIBA 0
#define ABAJO 1 
#define DERECHA 2
#define IZQUIERDA 3
#include "tSala.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
class tMap {
public:
	tSala playerLocation ,norte,sur,este,oeste;
	tMap();
	void ir(int door);
};

#endif
