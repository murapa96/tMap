#ifndef _TILESET_
#define _TILESET_

class tileSet{
	public:
		tileSet();
		void rotate();
		tileSet getTileSet();
	private:
		int container[TILEX][TILEY];
}

#endif
