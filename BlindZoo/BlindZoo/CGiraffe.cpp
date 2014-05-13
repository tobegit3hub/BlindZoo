//CElephant.cpp

#include"CGiraffe.h"

CGiraffe::CGiraffe()
{
	m_Species = GIRAFFE;
	m_Head = SMALLHEAD;
	m_Neck = LONGNECK;
	m_Body = STRONGBODY;
	m_Tail = SHORTTAIL;
}

CGiraffe::~CGiraffe()
{

}


void CGiraffe::Charateristic()
{
	cout<<"OK, it's neck is really, really LONG."<<endl;
}
