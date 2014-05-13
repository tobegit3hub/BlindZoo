//CElephant.h

#ifndef _H_CElephant
#define _H_CElephant

#include"CAnimal.h"

class CElephant: public CAnimal		//refer to CAnimal.h
{
private:

public:
	CElephant();
	virtual ~CElephant();
	
	virtual void Charateristic();		//must reload to show specific elephant
};



#endif