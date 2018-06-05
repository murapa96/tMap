#include "tMap.h"
#include "tSala.h"

tMap::tMap()
/*
 * 
 * tMap::tMap
 * Constructor de la clase tMap, clase que contiene las diversas salas al que jugador se puede ir moviendo.
 * También contiene la sala en la que se encuentra actualmente como la capacidad de moverse por ellas.
 *	Inicializa a partir de las puertas disponibles de la sala del Spawn salas aleatorias alrededor.
 * 
 */

{
	playerLocation = tSala();   //Inicializamos la posicion del jugador, este será siempre la sala en la que se encuentra el jugador.
	playerLocation.generateTileSet(); //Antes, el tileSet se generaba en el propio constructor de tSala. He decidido separarlo como función.
/*
 *Se comprueba la existencia de puertas en la sala generada. 
 * Las puertas usan lógica inversa, decisión propia. 
 * Si no existe una puerta, se genera una sala vacia (id = -1) esto se repite en el codigo.
 */		
		if(playerLocation.este == false)
			este =   tSala();
		else
			este =   tSala(-1);
		if(playerLocation .oeste == false)
			oeste =   tSala();
		else
			oeste =  tSala(-1);
		if(playerLocation .norte == false)
			norte =   tSala();
		else
			norte =  tSala(-1);
		if(playerLocation .sur == false)
			sur =   tSala();
		else
			sur =  tSala(-1);
		
}
void tMap::ir(int door) /*0 -> Norte, 1 -> Sur, 2-> Este, 3-> Oeste* / 
/*
 * Solo comentaré la primera función porque esto en un fúturo será la función "ir".
 * Basicamente, si existe sala (es decir, hay puerta y no es una sala nula)
 * substituye el valor de playerLocation por el valor de la sala en el norte, en el sur, en el este o en el oeste. 
 * 
 */
{
	bool done = false;
	switch(door){
		case 0:
			if ((norte.id != -1)&&(playerLocation.norte==false)){ //Se comprueba si existe sala.
				playerLocation = norte; //Movemos la sala a nosotros.
				sur=tSala(); //Se crea sala en el sur.
				playerLocation . sur = true; //Aunque se cierra la puerta
				playerLocation.generateTileSet();  //generamos el tileSet. para que cuente la puerta cerrada.
				done = true;
			}
		break;
		case 1:
			if ((sur.id != -1)&&(playerLocation.sur==false)){ //Se comprueba si existe sala.
				playerLocation = sur; //Movemos la sala a nosotros.
				norte=tSala(); //Se crea sala en el sur.
				playerLocation.norte = true; //Aunque se cierra la puerta
				playerLocation.generateTileSet();  //generamos el tileSet. para que cuente la puerta cerrada.
				done = true;
			}
		break;
		case 2:
			if ((este.id != -1)&&(playerLocation.este==false)){ //Se comprueba si existe sala.
				playerLocation = este; //Movemos la sala a nosotros.
				oeste=tSala(); //Se crea sala en el sur.
				playerLocation.oeste = true; //Aunque se cierra la puerta
				playerLocation.generateTileSet();  //generamos el tileSet. para que cuente la puerta cerrada.
				done = true;
			}
		break;
		case 3:
			if ((oeste.id != -1)&&(playerLocation.oeste==false)){ //Se comprueba si existe sala.
				playerLocation = oeste; //Movemos la sala a nosotros.
				este=tSala(); //Se crea sala en el sur.
				playerLocation.este = true; //Aunque se cierra la puerta
				playerLocation.generateTileSet();  //generamos el tileSet. para que cuente la puerta cerrada.
				done = true;
			}
		break;
			
	}
		if(done){
			if(playerLocation .este == false)  //Y como vimos en el primer caso, se comprueban las puertas y se crean las salas.
				este =   tSala();
			else
				este = tSala(-1);
			if(playerLocation .oeste == false)
				oeste =   tSala();
			else
				oeste = tSala(-1);
			if(playerLocation .norte == false)
				norte =   tSala();
			else
				norte = tSala(-1);
			if(playerLocation .sur == false)
				sur =   tSala();
			else
				sur =   tSala(-1);
	}
}
