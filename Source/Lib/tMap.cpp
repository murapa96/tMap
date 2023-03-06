#include "tMap.h"
#include "tSala.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
/*0 -> norte, 1 - > oeste,2->sur, 3->este */
tMap::tMap()
{
	pLocation = new tSala();
	srand((unsigned)time(0));
}
void tMap::irNorte()
{
	srand((unsigned)time(0));

	if (pLocation->norte == 1) {
		tSala *aux;
		aux = pLocation;
		pLocation = new tSala(2);
		free(aux);
	}
}
void tMap::irSur()
{
	srand((unsigned)time(0));

	if (pLocation->sur == 1) {
		tSala *aux;
		aux = pLocation;
		pLocation = new tSala(0);
		delete(aux);
	}
}
void tMap::irEste()
{
	srand((unsigned)time(0));

	if (pLocation->este == 1) {
		tSala *aux; 
		aux = pLocation;
		pLocation = new tSala(1);
		delete(aux);
	}
}

void tMap::irOeste()
{
	srand((unsigned)time(0));

	if (pLocation->oeste == 1) {
		tSala *aux;
		aux = pLocation;
		pLocation = new tSala(3);
		delete(aux);
	}
}
