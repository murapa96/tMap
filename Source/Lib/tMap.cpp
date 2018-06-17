#include "tMap.h"
tMap::~tMap(){

}
tMap::tMap(int generationType, int nSalas, int seed){
	this->generationType = generationType;
	this->nSalas = nSalas;
	this->seed=seed;
	if(seed == 0)
		this->seed = unsigned(time(0));
	srand(seed);
	cout <<"Creando NODO...\n";
	tNode nodo = nuevoNodo();
	tPos nuevoElemento = &nodo;
	cout <<"NODO CREADO";
	posBank.push_back(nuevoElemento);
	this -> mapa =	posBank.front();
	nSalas--;
	
	switch(this->generationType){
		case 0:
			generadorIterativo();
			break;
		case 2:
			generadorMultithread();
			break;
		default:
			cout << "generador runtime";
	}
	
	nSalas = nSalas;
	this -> currentLocation = mapa;
	
}

tSala tMap::getCurrentSala(){
	return currentLocation->sala;
}
void tMap::goUp(){
	if(currentLocation->doorUp == true){
		if(generationType == 1){
			generarArriba(currentLocation);
		}
		currentLocation = currentLocation -> nodeUp;
	}
}
void tMap::goDown(){
	if(currentLocation->doorDown == true){	
		if(generationType == 1){
			generarAbajo(currentLocation);
		}
		currentLocation = currentLocation -> nodeDown;
	}
}
void tMap::goLeft(){
	if(currentLocation->doorLeft == true){
		if(generationType == 1){
			generarIzquierda(currentLocation);
		}
		currentLocation = currentLocation -> nodeLeft;
	}
}
void tMap::goRight(){
	if(currentLocation->doorRight == true){
		if(generationType == 1){
			generarDerecha(currentLocation);
		}
		currentLocation = currentLocation -> nodeRight;
	}
}

int tMap::getNumberSalas(){
	return nSalas;
}
void tMap::generarArriba(tPos pos){
	tNode aux = nuevoNodo();
	if((nSalas > 0)&&(generationType!=1)){
		pos -> nodeUp = &aux;
		pos -> nodeUp -> nodeDown = pos;
		pos -> nodeUp -> doorDown = true;
		pos = pos -> nodeUp;
		posBank.push_back(pos);
		nSalas--;
	}else if(generationType==1){
		pos -> nodeUp = &aux;
		pos -> nodeUp -> nodeDown = pos;
		pos -> nodeUp -> doorDown = true;
		pos = pos -> nodeUp;
		posBank.push_back(pos);
		nSalas++;
	}
}
void tMap::generarAbajo(tPos pos){
	tNode aux = nuevoNodo();
	if((nSalas > 0)&&(generationType!=1)){
		pos -> nodeDown = &aux;
		pos -> nodeDown -> nodeUp = pos;
		pos -> nodeDown -> doorUp = true;
		pos = pos -> nodeDown;
		posBank.push_back(pos);
		nSalas--;
	}else if(generationType==1){
		pos -> nodeDown = &aux;
		pos -> nodeDown-> nodeUp = pos;
		pos -> nodeDown-> doorUp = true;
		pos = pos -> nodeDown;
		posBank.push_back(pos);
		nSalas++;
	}
}
void tMap::generarIzquierda(tPos pos){
	tNode aux = nuevoNodo();
	if((nSalas > 0)&&(generationType!=1)){
		pos -> nodeLeft = &aux;
		pos -> nodeLeft -> nodeRight = pos;
		pos -> nodeLeft -> doorRight = true;
		pos = pos -> nodeLeft;
		posBank.push_back(pos);
		nSalas--;
	}else if(generationType==1){
		pos -> nodeLeft = &aux;
		pos -> nodeLeft -> nodeRight = pos;
		pos -> nodeLeft -> doorRight = true;
		pos = pos -> nodeLeft;
		posBank.push_back(pos);
		nSalas++;
	}
}
void tMap::generarDerecha(tPos pos){
	tNode aux = nuevoNodo();
	if((nSalas > 0)&&(generationType!=1)){
		pos -> nodeRight = &aux;
		pos -> nodeRight -> nodeLeft = pos;
		pos -> nodeRight -> doorLeft = true;
		pos = pos -> nodeRight;
		posBank.push_back(pos);
		nSalas--;
	}else if(generationType==1){
		pos -> nodeRight = &aux;
		pos -> nodeRight -> nodeLeft = pos;
		pos -> nodeRight -> doorLeft = true;
		pos = pos -> nodeRight;
		posBank.push_back(pos);
		nSalas++;
	}
}
tNode tMap::nuevoNodo(){
	tNode aux;
	aux.sala = tSala();
	aux.doorUp = (rand() % 100 < PROUP);
	aux.doorLeft = (rand () % 100 < PROLEFT);
	aux.doorRight = (rand () % 100 < PRORIGHT);
	aux.doorDown = (rand () % 100 < PRODOWN);
	aux.nodeUp = NULL;
	aux.nodeDown = NULL;
	aux.nodeLeft = NULL;
	aux.nodeRight = NULL;
	return aux;
}
void tMap::generadorIterativo(){
	while(nSalas > 0){
		for(size_t i = 0;i < posBank.size(); i++){
			if(posBank[i]->doorUp == true)
				generarArriba(posBank[i]);
			if(posBank[i]->doorDown == true)
				generarAbajo(posBank[i]);
			if(posBank[i]->doorLeft == true)
				generarIzquierda(posBank[i]);
			if(posBank[i]->doorRight == true)
				generarDerecha(posBank[i]);
		}
	}
	for(size_t i = 0;i < posBank.size(); i++){
		if((posBank[i]->doorUp == true)&&(posBank[i]->nodeUp == NULL))
			posBank[i]->doorUp = false;
		if((posBank[i]->doorDown == true)&&(posBank[i]->nodeDown == NULL))
			posBank[i]->doorDown = false;
		if((posBank[i]->doorLeft == true)&&(posBank[i]->nodeLeft == NULL))
			posBank[i]->doorLeft = false;
		if((posBank[i]->doorRight == true)&&(posBank[i]->nodeRight == NULL))
			posBank[i]->doorRight = false;
	}
}
void tMap::generadorMultithread(){

}
