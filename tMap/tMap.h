#ifndef _TMAP_H_
#define _TMAP_H_
#include "defineMap.h"
#include "tSala.h"

///////////////////////////////CLASS tMap///////////////////////////////

class tMap{
	private:


	int nsalas;
	tSala array[MAXX][MAXY];
	unsigned int seed;
	
	public:
//Constructor sin semilla	
	tMap(int numSalas){ 
		int x = MAXX/2, y = MAXY/2;
		this->seed = time(NULL);
		bool control=false;
		
		srand(seed);
		this->nsalas = numSalas;
		while(nsalas>0){
			while(control == false){
				
				if (!array[x][y]) {
					array[x][y].id = 1 + rand() % MAXID ;
					nsalas--;
				}
				
				crearPuertas(x,y);
				
				if(((1 + rand() % 100) > PNORTE)&&(array[x][y].Norte == 0)){
					array[x][y-1].id = 1 + rand() % MAXID ;
					array[x][y-1].Sur = 3;
					array[x][y].Norte = 1;
					nsalas--;
					control = true;
				}
				
				if(this->nsalas==0) break;
				
				if(((1 + rand() % 100) > PESTE)&&(array[x][y].Este==0)){
					array[x+1][y].id = 1 + rand() % MAXID;
					array[x+1][y].Oeste = 3;
					array[x][y].Este = 1;
					nsalas--;
					control = true;
				}
				
				if(nsalas==0) break;
				
				if(((1 + rand() % 100) > POESTE)&&(array[x][y].Oeste == 0)){
					array[x-1][y].id = 1 + rand() % MAXID ;
					array[x-1][y].Este = 3;
					array[x][y].Oeste = 1;
					nsalas--;
					control = true;
				}
				
				if(nsalas==0) break;
				
				if(((1 + rand() % 100) > PSUR)&&(array[x][y].Sur == 0)){
					array[x][y+1].id = 1 + rand() % MAXID ;
					array[x][y+1].Norte = 3;
					array[x][y].Sur = 1;
					nsalas--;
					control = true;
				}
				
				switch(rand()%4){
					case 0:
						if((array[x][y].Norte == 1)&&(y>1))
						{
							y--;
						}
						break;
					case 1:
						if((array[x][y].Oeste == 1)&&(x>1))
						{
							x--;
						}
						break;
					case 2:
						if((array[x][y].Sur == 1)&&(y<MAXY-1))
						{
							y++;
						}
						break;
					case 3:
						if((array[x][y].Este == 1)&&(x<MAXX-1))
						{
							x++;
						}
						break;
					
				}
			}
				control = false;
			}
			
		
		nsalas = numSalas;
	}

//Constructor con semilla	
	tMap(unsigned int iSeed,int numSalas){ 
		int x = MAXX/2, y = MAXY/2;
		bool control=false;
		this->seed = iSeed;
		srand(seed);
		this->nsalas = numSalas;
		while(nsalas>0){
			
			while(control == false){
				if (!array[x][y]) {
					array[x][y].id = 1 + rand() % MAXID ;
					nsalas--;
				}
				crearPuertas(x,y);
				if(((1 + rand() % 100) > PNORTE)&&(array[x][y].Norte == 0)){
					array[x][y-1].id = 1 + rand() % MAXID ;
					array[x][y-1].Sur = 3;
					array[x][y].Norte = 1;
					nsalas--;
					control = true;
				}
				
				if(this->nsalas==0) break;
				
				if(((1 + rand() % 100) > PESTE)&&(array[x][y].Este == 0)){
					array[x+1][y].id = 1 + rand() % MAXID ;
					array[x+1][y].Oeste = 3;
					array[x][y].Este = 1;
					nsalas--;
					control = true;
				}
				
				if(nsalas==0) break;
				
				if(((1 + rand() % 100) > POESTE)&&(array[x][y].Oeste == 0)){
					array[x-1][y].id = 1 + rand() % MAXID ;
					array[x-1][y].Este = 3;
					array[x][y].Oeste = 1;
					nsalas--;
					control = true;
				}
				
				if(nsalas==0) break;
				
				if(((1 + rand() % 100) > PSUR)&&(array[x][y].Sur == 0)){
					array[x][y+1].id = 1 + rand() % MAXID ;
					array[x][y+1].Norte = 3;
					array[x][y].Sur = 1;
					nsalas--;
					control = true;
				}
				
				switch(rand()%4){
					case 0:
						if((array[x][y].Norte == 1)&&(y>1))
						{
							y--;
						}
						break;
					case 1:
						if((array[x][y].Oeste == 1)&&(x>1))
						{
							x--;
						}
						break;
					case 2:
						if((array[x][y].Sur == 1)&&(y<MAXY-1))
						{
							y++;
						}
						break;
					case 3:
						if((array[x][y].Este == 1)&&(x<MAXX-1))
						{
							x++;
						}
						break;
					
				}
			}
				control = false;
			}
			
		
		nsalas = numSalas;
	}
	
	
	void print(){
		cout<<"Seed:"<<this->seed<<"\n";
		for(int i = 0;i<MAXY;i++){
			for(int j = 0;j<MAXX;j++){
				if(!array[j][i]){
					cout <<" "<<" "<<" ";
				}else{
					cout <<" "<<array[j][i].id<<" ";
				}
			}
			cout << "\n";
		}
	}
	
	
	tSala getSala(int x, int y){
		return array[x][y];
	}
	
	unsigned int getSeed(){
		return this->seed;
	}
	
	
	private:
	void crearPuertas(int x, int y){
		array[x][y].Norte = (array[x][y-1].isSala() ? 1:0 );
		array[x][y].Este = (array[x+1][y].isSala() ? 1:0 );
		array[x][y].Oeste = (array[x-1][y].isSala() ? 1:0 );
		array[x][y].Sur = (array[x][y+1].isSala() ? 1:0 );
	}
	
};

///////////////////////////////END CLASS tMap///////////////////////////

#endif
