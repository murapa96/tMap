#include "tMap.h"

tMap::tMap(int numSalas){ 
	int x = MAXX/2, y = MAXY/2;
	pX = x; pY = y; 
	this->seed = time(NULL);
	bool control=false;
	srand(seed);
	this->nsalas = numSalas;
	generate(nsalas,x,y);
	crearPuertas();
	array[pX][pY].generateTileSet();
	playerLocation = getSala(pX,pY);
	nsalas = numSalas;
}
	
tMap::tMap(unsigned int iSeed,int numSalas){ 
	int x = MAXX/2, y = MAXY/2;
	pX = x;
	pY=y;
	bool control=false;
	this->seed = iSeed;
	srand(seed);
	this->nsalas = numSalas;
	generate(nsalas,x,y);
	crearPuertas();
	array[pX][pY].generateTileSet();
	playerLocation = getSala(pX,pY);
	nsalas = numSalas;
}
	
	
tSala tMap::getSala(int x, int y){
	return array[x][y];
}

unsigned int tMap::getSeed(){
	return this->seed;
}



void tMap::crearPuertas(){
	for(int x = 1; x < MAXX-1;x++){
		for(int y = 1; y < MAXY-1; y++){
			array[x][y].norte = (array[x][y-1].isSala() ? false:true );
			array[x][y].este = (array[x+1][y].isSala() ? false:true );
			array[x][y].oeste = (array[x-1][y].isSala() ? false:true );
			array[x][y].sur = (array[x][y+1].isSala() ? false:true );
			array[x][y].generateTileSet();

		}
	}
}
	
		
void tMap::ir(int door){
	switch(door){
		case ARRIBA:
			if(array[pX][pY--].isSala()){
			pY--;
			playerLocation = getSala(pX,pY);
		}
		break;
		case ABAJO:
			if(array[pX][pY++].isSala()){
			pY++;
			playerLocation = getSala(pX,pY);
		}
		break;
		case IZQUIERDA:
			if(array[pX--][pY].isSala()){
			pX--;
			playerLocation = getSala(pX,pY);

		}
		break;
		case DERECHA:
			if(array[pX++][pY].isSala()){
			pX++;
			playerLocation = getSala(pX,pY);
		}
		break;
	}
	

}

void tMap::generate(int numSalas,int x,int y){
	int nusalas = numSalas;
	if(numSalas > 0){	
		if (!array[x][y]) {
			array[x][y] = tSala();

			nusalas--;
		}
		switch(rand()% 4){
			case 0:
			if((array[x][y].norte == false)&&(y>1))
				generate(nusalas - 1,x,y-1);
			else
				array[x][y].norte = true;
			break;
			case 1:
			if((array[x][y].oeste == false)&&(x>1))
				generate(nusalas - 1,x-1,y);
			else
				array[x][y].oeste = true;
			break;
			case 2:
			if((array[x][y].sur == false)&&(y<MAXY-1))
				generate(nsalas - 1,x,y+1);
			else
				array[x][y].sur = true;
			break;
			case 3:
			if((array[x][y].este == false)&&(x<MAXX-1))
				generate(nusalas - 1,x+1,y);
			else
				array[x][y].este = true;
			break;
		}
	}
}
