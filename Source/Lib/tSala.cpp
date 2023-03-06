#include "tSala.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
tSala::tSala(int _norte, int _oeste, int _sur, int _este) :norte(_norte), oeste(_oeste), sur(_sur), este(_este)
{
	srand(unsigned(time(0)));
	id = rand() % 50 + 1;
	generateTileSet();

}

tSala::tSala(int puertaEntrada /*0 -> norte, 1 - > oeste,2->sur, 3->este */) {
	norte = 0;
	sur = 0;
	este = 0;
	oeste = 0;
	srand((unsigned)time(0));
	switch (puertaEntrada) {
		case 0:
				while(oeste + sur + este == 0) {
					if ((oeste = rand() % 3) == 2) oeste = oeste / 2;
					if ((sur = rand() % 3) == 2) sur = sur / 2;
					if ((este = rand() % 3) == 2) este = este / 2;
				}
				norte = 2;
			break;
		case 1:
			while (norte + sur + este == 0) {
				if ((norte = rand() % 3)==2) norte=norte/2;
				if ((sur = rand() % 3)==2) sur = sur /2;
				if ((este = rand() % 3)==2) este = este /2;
			}
			oeste = 2;
			break;
		case 2:
			while (norte + oeste + este == 0) {
				if ((norte = rand() % 3) == 2) norte = norte / 2;
				if ((oeste = rand() % 3) == 2) oeste = oeste / 2;	
				if ((este = rand() % 3) == 2) este = este / 2;
			}
			sur = 2;
			break;
		case 3:
			while (norte + oeste + sur == 0) {
				if ((norte = rand() % 3) == 2) norte = norte / 2;
				if ((sur = rand() % 3) == 2) sur = sur / 2;
				if ((oeste = rand() % 3) == 2) oeste = oeste / 2;
			}
			este = 2;
			break;
	}
		generateTileSet();


}


tSala::tSala() 
{
	norte = 0;
	sur = 0;
	este = 0;
	oeste = 0;
	srand(unsigned(time(0)));
	id = rand() % 50 + 1;
		while (norte + oeste + sur + este == 0) {
			if ((norte = rand() % 3) == 2) norte = norte / 2;
			if ((sur = rand() % 3) == 2) sur = sur / 2;
			if ((oeste = rand() % 3) == 2) oeste = oeste / 2;
			if ((este = rand() % 3) == 2) este = este / 2;
		}
	generateTileSet();


}
void tSala::generateTileSet(){
    srand(unsigned(time(0)));
    for (int i = 0; i< 22; i++)
		for(int j = 0; j<22; j++)
			tileMap[i][j] = 0;
    for(int y = 1 ; y < 20 ; y++ ){
        if(y == 10){
            for (int x = 1;x < 20; x++)
                tileMap[x][y] = 1;
        }else{
			tileMap[10][y] = 1;
        for (int x = 1,generatedNumber = 0;x < 10; x++){
			generatedNumber=((rand() % 3)+1);
			if(generatedNumber > 1)
				if(rand() % 2 == 1)
					generatedNumber = 1;
			tileMap[10-x][y] = generatedNumber;
			tileMap[10+x][y] = generatedNumber;
       }
   }
    }
    if(this->norte == 1)
        tileMap[10][0] = 4; //ID correcto 500
    if(this->sur == 1)
        tileMap[10][21] = 4; //Id correcto 499
    if(this ->este == 1)
        tileMap[0][10] = 4; //ID correcto 498
    if(this -> oeste == 1)
        tileMap[21][10] = 4; //ID correcto 497

    
}

void tSala::printTileSet(){
        for(int x = 0 ; x < 21 ; x++ ){
            for (int y = 0;y < 21; y++)
                cout <<" "<<tileMap[y][x]<<" ";
        cout << "\n";
    }
}



	
