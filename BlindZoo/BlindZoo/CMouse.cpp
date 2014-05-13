//CMouse.cpp

#include"CMouse.h"

CMouse::CMouse()
{
	m_Species = MOUSE;
	m_Head = SMALLHEAD;
	m_Neck = NONECK;
	m_Body = THINBODY;
	m_Tail = LONGTAIL;
}

CMouse::~CMouse()
{

}

void CMouse::Charateristic()
{
	cout<<"OK, it's not only bad-looking but also smelly."<<endl;
}
