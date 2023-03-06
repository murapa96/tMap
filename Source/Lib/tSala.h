#ifndef T_SALA
#define T_SALA
#include <iostream>
#include <cstdlib>
#include <ctime>

class tSala {
public:
	int tileMap[22] [22];
	int norte, oeste, sur, este, id;
	tSala(int _norte, int _oeste, int _sur, int _este);
	tSala(int puertaEntrada);
	tSala();
    void printTileSet();
private:
    int tileRow[10];
    void generateTileSet();
    
};
#endif // !T_SALA

