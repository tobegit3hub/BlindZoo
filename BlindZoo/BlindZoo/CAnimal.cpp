//CAnimal.cpp

#include"CAnimal.h"


CAnimal::CAnimal()
{
	m_Species = DEFSPECIES;
	m_Head = DEFHEAD;
	m_Neck = DEFNECK;
	m_Body = DEFBODY;
	m_Tail = DEFTAIL;
}

CAnimal::~CAnimal()
{

}


void CAnimal::Touch(EOrgan Organ)
{
	switch(Organ)
	{
	case HEAD:
		{
			switch(m_Head)
			{
			case BIGHEAD:
				{
					cout<<"OK, it has a BIG head."<<endl;
				}break;
			case SMALLHEAD:
				{
					cout<<"OK, it has a SMALL head."<<endl;
				}break;
			}
		}break;

	case NECK:
		{
			switch(m_Neck)
			{
			case LONGNECK:
				{
					cout<<"OK, it has a LONG neck."<<endl;
				}break;
			case SHORTNECK:
				{
					cout<<"OK, it has a SHORT neck."<<endl;
				}break;
			case NONECK:
				{
					cout<<"OK, it has NO neck"<<endl;
				}break;
			}
		}break;

	case BODY:
		{
			switch(m_Body)
			{
			case STRONGBODY:
				{
					cout<<"OK, it has a STRONG body."<<endl;
				}break;
			case THINBODY:
				{
					cout<<"OK, it has a THIN body."<<endl;
				}break;
			}
		}break;

	case TAIL:
		{
			switch(m_Tail)
			{
			case LONGTAIL:
				{
					cout<<"OK, it has a LONG tail."<<endl;
				}break;
			case SHORTTAIL:
				{
					cout<<"OK, it has a SHORT tail."<<endl;
				}break;
			case NOTAIL:
				{
					cout<<"OK, it has NO tail"<<endl;
				}break;
			}
		}break;


	case SPECIES:
		{
			switch(m_Species)
			{
			case ELEPHANT:
				{
					cout<<"All right, it is a ELEPHANT."<<endl;
				}break;
			case GIRAFFE:
				{
					cout<<"All right, it is a GIRAFFE."<<endl;
				}break;
			case MOUSE:
				{
					cout<<"All right, it is a MOUSE."<<endl;
				}break;
			case TIGER:
				{
					cout<<"All right, it is a TIGER."<<endl;
				}break;
			}
		}break;		
	}
}

