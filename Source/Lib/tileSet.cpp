#include "tileSet.h"

tileSet::tileSet(int seed = 0){
	
	if(seed == 0)	
		srand(unsigned(time(0))); //Inicializamos el Random.
    else
		srand(unsigned(seed));
		
    for (int x = 0; i< TILEX; x++) 
		for(int y = 0; j<TILEY; y++)
			container[x][y] = 0; //Antes de comenzar la generación, pongo todo el tileset a 0.
//Ahora dos fors que recorren el array bidimensional generando numeros aleatorios.
    for(int x = 1 ; x < (TILEX-1) ; x++ ){ 
		container[x][10] = 1;
        for(int y = 1,generatedNumber = 0;y < ((TILEY - 1)/ 2); y++){
			generatedNumber=((rand() % 3)+1);
			if(generatedNumber > 1) //Si no es suelo, se hace un rand en modulo dos y se compara con 1
				if((rand() % 2 == 1)||(x==10))
					generatedNumber = 1; //Si es true se vuelve tierra.
			if(0<10-y)
				container[x][10-y] = generatedNumber;
			container[x][10+y] = generatedNumber;  //Se rellena el suelo de forma simetrica.
       }
    }
}


tileSet::rotate(){
	for(int x = 0; x < TILEX; x++){
		for(int y = 0; y < TILEY; y++){
			temp = container[y][x];
			container[y][x] = container[x][y];
			container[x][y] = temp;
		}
	}
}

tileSet tileSet::getTileSet(){
	return this->container;
}
