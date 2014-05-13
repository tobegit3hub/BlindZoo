//CTiger.cpp

#include"CTiger.h"

CTiger::CTiger()
{
	m_Species = TIGER;
	m_Head = BIGHEAD;
	m_Neck = SHORTNECK;
	m_Body = STRONGBODY;
	m_Tail = SHORTTAIL;
}

CTiger::~CTiger()
{

}

void CTiger::Charateristic()
{
	cout<<"OK, it is called King Of The Forest."<<endl;
}
