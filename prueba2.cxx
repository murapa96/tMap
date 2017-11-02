/*
 * prueba2.cxx
 * Prograna ejemplo de prueba para la libreria tMap especificada
 * para la generacion aleatoria de mapas en 2d.
 * 
 * 
 * 
 * Copyright 2017 Pablo Ramos Muras <pablo@MaggiSystem>
 * 
 * 
 * 
 */


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "tMap/tMap.h"

int main(int argc, char **argv)
{
	tMap prueba = tMap(400);
	tSala hab;
	cout << "done!\n";
	prueba.print();
	hab = prueba.getSala(14,12);
	
	if(hab.isSala()){
		cout << "True!";
	}
	else{
		cout << "False!";
	}
	
	hab.print();
	
	cout<<"\n"<<prueba.getSeed();
	
	return 0;
}

