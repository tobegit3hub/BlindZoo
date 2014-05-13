//CGiraffe.h

#ifndef _H_CGiraffe
#define _H_CGiraffe

#include"CAnimal.h"

class CGiraffe: public CAnimal		//refer to CAnimal.h
{
private:

public:
	CGiraffe();
	virtual ~CGiraffe();
	
	virtual void Charateristic();		//must reload to show specific giraffe
};



#endif