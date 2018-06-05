#ifndef T_SALA
#define T_SALA
#include <iostream>
#include <cstdlib>
#include <ctime>

class tSala {
public:
	int tileMap[23] [23];
	int id;
	bool norte, oeste, sur, este; 
	tSala();
	tSala(int id);
    void printTileSet();
    void generateTileSet();
private:
   
    
    
};
#endif // !T_SALA

