#ifndef _TSALA_H_
#define _TSALA_H_
#define MAXH 10
#define MAXB 10
#include <iostream>
#include <fstream>

///////////////////////////////CLASS tSALA//////////////////////////////
class tListSala{
	public:
	typedef struct Sala{
		int id;
		int array[][];
		int type;
	}Sala;
	Sala NULL={0,{0},0};
	Sala almacen[];
	int max = 0;
	
	tListSala():almacen({NULL});
	
	tListSala(string fileName){
		ifstream myReadFile;
		try{
			myReadFile.open(fileName.c_str());
			if(!myReadFile.is_open()){
				throw 20;
			}
		}
		catch(int e)
		{
			cout << "MISSING FILE "<<fileName;
		}
		
		
		myReadFile >> id;
		myReadFile.close();
		//
	}
	Sala searchById(int id){
		for(int i = 0; i < max ; i++){
			if(almacen[i].id == id) 
				return almacen[i];
		}
		return NULL;
	}
	int addListToList(String filename){
		//TODO
	}
	
	int addSalaToList(Sala sala){
		//TODO
	}
};

///////////////////////////////END CLASS tSALA//////////////////////////
#endif
