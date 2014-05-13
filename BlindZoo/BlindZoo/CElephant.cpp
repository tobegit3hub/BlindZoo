//CElephant.cpp

#include"CElephant.h"

CElephant::CElephant()
{
	m_Species = ELEPHANT;
	m_Head = BIGHEAD;
	m_Neck = NONECK;
	m_Body = STRONGBODY;
	m_Tail = SHORTTAIL;
}

CElephant::~CElephant()
{

}

void CElephant::Charateristic()
{
	cout<<"OK, it also has a LONG trunk."<<endl;
}
