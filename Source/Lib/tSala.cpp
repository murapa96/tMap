#include "tSala.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
tSala::tSala(int seed)
/*
 *Constructor para poder crear la sala vacia con el id -1
 * 
 * 
 * 
 */

{
	this->seed = seed;
	tileMap = new tileSet(seed);
	tileMap->rotate();
	//srand(seed);
	this->id = rand() % (MAXID+1);
}

tSala::tSala()
 
{
	seed = time(NULL);
	tileMap =new tileSet(seed);
	tileMap->rotate();
	srand(unsigned(seed));
	this->id = rand() % (MAXID+1);
}


bool tSala::operator!(){
		return this->id == 0;
}

bool tSala::isSala(){
		if(this->id ==0)
			return false;
		return true;
}

void tSala::printTileSet(){
        for(int x = 0 ; x < 21 ; x++ ){
            for (int y = 0;y < 21; y++)
                cout <<" "<<tileMap->_TILESET[x][y]<<" ";
        cout << "\n";
    }
}



	
