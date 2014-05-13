//CAnimal.h

#ifndef _H_CAnimal
#define _H_CAnimal

#include"afx.h"

class CAnimal		//the basic class of all the animals
{
private:

public:
	ESpecies m_Species;		//the specific species
	EHead m_Head;		//the kinds of head
	ENeck m_Neck;		//the kinds of neck
	EBody m_Body;		//the kinds of body
	ETail m_Tail;		//the kinds of tail

	CAnimal();		//initialize all the data member
	virtual ~CAnimal();		//do nothing
	void Touch(EOrgan Organ);		//reaction for touch depending on different part

	virtual void Charateristic()=0;		//need to reload to show specific animal
};



#endif