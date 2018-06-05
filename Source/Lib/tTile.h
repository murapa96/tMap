#pragma once
#include <string>
#include <iostream>
class tTile
{
public:
	tTile(int id, bool walkAble,std::string nameTile,int imX,int imY);
	int id;
	int imX,imY;
	bool walkAble;
	std::string nameTile;
	
};

