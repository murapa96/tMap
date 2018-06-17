#include <cstdlib>
#include <ctime>
#include "defineMap.h"
#include "tileSet.h"
tileSet::tileSet(int seed){
	
	if(seed == 0)	
		srand(unsigned(time(0))); //Inicializamos el Random.
    else
		srand(unsigned(seed));
		
    for (int x = 0; x< TILEX; x++) 
		for(int y = 0; y<TILEY; y++)
			_TILESET[x][y] = 0; //Antes de comenzar la generación, pongo todo el tileset a 0.
//Ahora dos fors que recorren el array bidimensional generando numeros aleatorios.
    for(int x = 1 ; x < (TILEX-1) ; x++ ){ 
		_TILESET[x][10] = 1;
        for(int y = 1,generatedNumber = 0;y < ((TILEY - 1)/ 2); y++){
			generatedNumber=((rand() % 3)+1);
			if(generatedNumber > 1) //Si no es suelo, se hace un rand en modulo dos y se compara con 1
				if((rand() % 2 == 1)||(x==10))
					generatedNumber = 1; //Si es true se vuelve tierra.
			if(0<10-y)
				_TILESET[x][10-y] = generatedNumber;
			_TILESET[x][10+y] = generatedNumber;  //Se rellena el suelo de forma simetrica.
       }
    }
}


void tileSet::rotate(){
	int aux;
	for(int x = 0; x < TILEX-1; x++){
		for(int y = 0; y < TILEY-1; y++){
			aux = _TILESET[y][x];
			_TILESET[y][x] = _TILESET[x][y];
			_TILESET[x][y] = aux;
		}
	}
}

void tileSet::setValue(int x, int y, int value){
	if((x < TILEX )&&(y < TILEY))
		_TILESET[x][y] = value;
}
