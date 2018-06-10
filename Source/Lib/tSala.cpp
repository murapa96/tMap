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
	seed = this->seed;
}

tSala::tSala()
/*
 *Constructor que unicamente genera las puertas aleatorias.
 * 
 * 
 * 
 * 
 */
 
{
	int generatedNumber = 1 + rand() % MAXID;
	norte = (generatedNumber >= 15);
	sur   = (generatedNumber <= 5);
	este  = (generatedNumber >= 13);
	oeste = (generatedNumber <= 9);

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
                cout <<" "<<tileMap[y][x]<<" ";
        cout << "\n";
    }
}



	
