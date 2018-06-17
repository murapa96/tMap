#ifndef _TMAP_H_
#define _TMAP_H_
#define ARRIBA 0
#define ABAJO 1 
#define DERECHA 2
#define IZQUIERDA 3
#define RUNTIME 1
#define ITERATIVE 0
#define MULTITHREAD 2
#include "defineMap.h"
#include "tSala.h"
#include <vector>
using namespace std;

///////////////////////////////CLASS tMap///////////////////////////////
typedef struct tNode tNode;
struct tNode{
	bool doorUp, doorDown, doorLeft, doorRight;
	tNode *nodeUp, *nodeDown, *nodeLeft, *nodeRight;
	tSala sala;
};

typedef tNode* tPos;
typedef tPos map;

class tMap{
	
	public:
		~tMap();
		tMap(int generationType, int nSalas, int seed);
		tSala getCurrentSala();
		void goUp();
		void goDown();
		void goLeft();
		void goRight();
		int getNumberSalas();
		tSala findById();
	private:
		tPos currentLocation;
		map mapa;
		int seed;
		int nSalas;
		int generationType;
		vector<tPos> posBank;
		void generarArriba(tPos pos);
		void generarAbajo(tPos pos);
		void generarIzquierda(tPos pos);
		void generarDerecha(tPos pos);
		tNode nuevoNodo();
		void generadorIterativo();
		void generadorMultithread();



};
#endif
