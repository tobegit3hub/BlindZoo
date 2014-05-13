//CZoo.cpp

#include"CZoo.h"

CZoo::CZoo()
{
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
			m_Map[i][j].Step = false;
	m_Map[1][1].Step = true;		//set the origin point steped

	ifstream in;
	in.open(".//Map.txt",ios::in);		//load the map
	if(!in)
	{
		cerr<<"NO MAP HERE !!! now use default map"<<endl;
		for(int i=0;i<10;++i)
			for(int j=0;j<10;++j)
				m_Map[i][j].Road = true;
		//abort();
	}
	else
	{
		char c;
		for(int i=0;i<10;++i)
		{
			for(int j=0;j<10;++j)
			{
				in.get(c);
				if('\n'==c)
					--j;
				else if('0'==c)                       
					m_Map[j][i].Road = false;
				else if('1'==c)
					m_Map[j][i].Road = true;
			}
		}
	}
	in.close();


	//m_Map[2][1].Tool = KEY;
	//m_Map[3][1].Tool = DOOR;
	//m_Map[2][8].Tool = KEY;
	//m_Map[8][7].Tool = DOOR;

	srand( time(0) );
	for(int i=0;i<10;++i)		//initialize the animal metrix and set NULL firstly
		for(int j=0;j<10;++j)
			m_pAnimal[i][j] = NULL;

	//m_pAnimal[2][1] = new CMouse;
	//m_pAnimal[3][1] = new CTiger;
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
			if(true==m_Map[i][j].Road)
				RandomAnimal(i, j);
}

CZoo::~CZoo()
{
	ReleaseAnimal();
}

void CZoo::ReleaseAnimal()
{
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			if(NULL!=m_pAnimal[i][j])
			{
				delete m_pAnimal[i][j];
				m_pAnimal[i][j] = NULL;
			}
		}
	}
}




void CZoo::EchoInfo()
{
	cout<<"     BlindZoo firstly was designed as a game for the blind, but it is not attractive enough without sound effect and screen-reading program. So it's super modified for non-blind people better to experience the blind lift. What's more, the souce code of this program will be distributed on the Internet, so no rights reserved."<<endl
		<<"     Now you are in the entrace of the zoo (1,1) and just go find your way to get out to exit (8,8). In this way, you are supposed to \"see\" some animals. Just try to touch them and find out what's that, which may let you know both bitter and fun of blind persons."<<endl
	    <<endl;
	cout<<"\t\tHere's The Commands That You Can Use:"<<endl
		<<"\t\tman      man, go, touch, is, get, open, kill"<<endl
		<<"\t\tgo       south, north, east, west"<<endl
		<<"\t\ttouch    head, neck, body, tail, more"<<endl
		<<"\t\tis       elephant, giraffe, mouse, tiger"<<endl
		<<"\t\tget      key"<<endl
		<<"\t\topen     door"<<endl
		<<"\t\tkill     myself"<<endl
		<<endl;		//to make a seperator
}


void CZoo::SetStep(int x, int y)
{
	m_Map[x][y].Step = true;
}

void CZoo::ShowStep()
{
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			if(m_Map[j][i].Step)
				cout<<'S'<<' ';
			else cout<<'0'<<' ';
		}
		cout<<endl;
	}
}



void CZoo::RandomAnimal(int x, int y)
{
	int res = rand() % 12;
	switch(res)
	{
	case 0:
		m_pAnimal[x][y] = new CElephant; break;
	case 1:
		m_pAnimal[x][y] = new CGiraffe; break;
	case 2:
		m_pAnimal[x][y] = new CMouse; break;
	case 3:
		m_pAnimal[x][y] = new CTiger; break;
	default:
		m_pAnimal[x][y] = NULL;
	}
}
