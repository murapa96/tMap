#include "tSala.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
tSala::tSala(int id)
/*
 *Constructor para poder crear la sala vacia con el id -1
 * 
 * 
 * 
 */

{
	id = id;
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
	srand(time(0));
	int generatedNumber = rand() % 20;
	norte = (generatedNumber >= 15);
	sur   = (generatedNumber <= 5);
	este  = (generatedNumber >= 13);
	oeste = (generatedNumber <= 9);

}
void tSala::generateTileSet()
/*
*El generador de tileSets... Realmente ni yo mismo entiendo muy bien este codigo.
* Cuando escribo este comentario realmente me estoy enfrentando a el. Tengo que optimizarlo,
* limpiarlo y comentarlo.
* 
*/
{
	srand(unsigned(time(0))); //Inicializamos el Random.
    
    for (int i = 0; i< 22; i++) 
		for(int j = 0; j<22; j++)
			tileMap[i][j] = 0; //Antes de comenzar la generación, pongo todo el tileset a 0.
		//Ahora dos fors que recorren el array bidimensional generando numeros aleatorios.
    for(int x = 1 ; x < 21 ; x++ ){ 
		tileMap[x][10] = 1;
        for(int y = 1,generatedNumber = 0;y < 11; y++){
			generatedNumber=((rand() % 3)+1);
			if(generatedNumber > 1) //Si no es suelo, se hace un rand en modulo dos y se compara con 1
				if((rand() % 2 == 1)||(x==10))
					generatedNumber = 1; //Si es true se vuelve tierra.
			if(0<10-y)
				tileMap[x][10-y] = generatedNumber;
			tileMap[x][10+y] = generatedNumber;  //Se rellena el suelo de forma simetrica.
       }
    }//Y aqui es lo raro, esto comprueba con logica negativa y rellena los huecos de las puertas.
    if(norte == false){
        tileMap[10][0] = 4;
        } //ID correcto 500
    if(sur == false){
        tileMap[10][21] = 4; //Id correcto 499
    }
    if(este == false){
        tileMap[0][10] = 4; //ID correcto 498
    }
    if(oeste == false){
        tileMap[21][10] = 4; //ID correcto 497
	}
    
}

void tSala::printTileSet(){
        for(int x = 0 ; x < 21 ; x++ ){
            for (int y = 0;y < 21; y++)
                cout <<" "<<tileMap[y][x]<<" ";
        cout << "\n";
    }
}



	
