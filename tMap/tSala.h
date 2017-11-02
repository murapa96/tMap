#ifndef _TSALA_H_
#define _TSALA_H_
#define MAXH 10
#define MAXB 10
#include <iostream>
#include <fstream>
using namespace std;

class tTile{
	int id;
};

///////////////////////////////CLASS tSALA//////////////////////////////
class tSala{
	public:
	int Norte,Sur,Este,Oeste;
	int id=0;
	tTile array[MAXB][MAXH];
	tSala(){
		//
	}
	
	tSala(string fileName){
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
	bool operator!(){
		return this->id == 0;
	}
	bool isSala(){
		if(this->id ==0)
			return false;
		return true;
	}
	void print(){
		cout << this->id;
	}
	
};

///////////////////////////////END CLASS tSALA//////////////////////////
#endif
