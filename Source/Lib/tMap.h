#ifndef _TMAP_H_
#define _TMAP_H_
#define ARRIBA 0
#define ABAJO 1 
#define DERECHA 2
#define IZQUIERDA 3
#include "defineMap.h"
#include "tSala.h"
using namespace std;

///////////////////////////////CLASS tMap///////////////////////////////

class tMap{
	private:
	int nsalas;	
	unsigned int seed;
	public:
	tSala array[MAXX][MAXY];
	tSala playerLocation;

//Constructor sin semilla	
	tMap(int numSalas);
//Constructor con semilla	
	tMap(unsigned int iSeed,int numSalas);
	void ir(int door);
	unsigned int getSeed();
	tSala getSala(int x, int y);
	private:
	void generate(int numSalas,int x,int y);
	int pX, pY;
	void crearPuertas();
	void selectorCamino(tSala array, int *x, int *y);
///////////////////////////////END CLASS tMap///////////////////////////

#endif
};
