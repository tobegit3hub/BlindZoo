//CMouse.h

#ifndef _H_CMouse
#define _H_CMouse

#include"CAnimal.h"

class CMouse: public CAnimal		//refer to CAnimal.h
{
private:

public:
	CMouse();
	virtual ~CMouse();
	
	virtual void Charateristic();		//must reload to show specific mouse
};



#endif