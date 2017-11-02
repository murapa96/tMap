#ifndef TTILE_H
#define TTILE_H
#define maxTiles 10
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class TileList{
	
	public:		
		
		typedef struct tile{
			int id;
			int damage;
			bool canWalkTrough;
			bool canShootThrough;	
		}tile;

		tile tiles [maxTiles];
		
		string tileMap;
		
	private:
		const tile VOIDTILE = {0,0,false,false}; 
		const tile VOID [maxTiles] = {VOIDTILE};	
	
		
	TileList():tiles(VOID){
		
	};
	
	tile getTile(int id){
		for(int i = 0; i <= maxTiles;i++){
			if(tiles[i].id == id)
				return tiles[i];	
		}	
	}
		
	void setTiles(string fileName){
		ifstream myReadFile;
		myReadFile.open(fileName);
		char output[100];
		if (myReadFile.is_open()) {
			while (!myReadFile.eof()) {
	    		myReadFile >> output;
	    		cout<<output;
			}
		}
		myReadFile.close();
	}	
}
#endif
