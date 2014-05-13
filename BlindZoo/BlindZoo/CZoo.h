//CZoo.h

#ifndef _H_CZoo
#define _H_CZoo

#include"CAnimal.h"
#include"CElephant.h"
#include"CGiraffe.h"
#include"CMouse.h"
#include"CTiger.h"


#include<fstream>		//to load the map by txt
#include<cstdlib>
#include<ctime>

class CZoo
{
private:

public:
	SBlock m_Map[10][10];		//define the map which contains some components
	CAnimal * m_pAnimal[10][10];		//define the two-dimention array to place animals

	CZoo();		//initialize the map and animals
	~CZoo();		//do nothing except for release the animal's pointer

	void EchoInfo();		//cout some information about commands
	void SetStep(int x, int y);		//record the steps user has already walked
	void ShowStep();		//show the steps user has already walked

	void RandomAnimal(int x, int j);		//place an animal in (x,y) or not randomly
	void ReleaseAnimal();		//release the animal's pointer
};



#endif