//CTiger.h

#ifndef _H_CTiger
#define _H_CTiger

#include"CAnimal.h"

class CTiger: public CAnimal		//refer to CAnimal.h
{
private:

public:
	CTiger();
	virtual ~CTiger();
	
	virtual void Charateristic();		//must reload to show specific tiger
};



#endif