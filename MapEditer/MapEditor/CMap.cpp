//CMap.cpp

#include"CMap.h"



CMap::CMap()
{
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			m_Map[i][j] = EMPTY;
		}
	}

	Frame();

	bModify = true;
}

CMap::~CMap()
{

}


void CMap::Frame()
{
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			if(0==i || 9==i || 0==j || 9==j)
				m_Map[i][j] = WALL;
		}
	}

	m_Map[1][1] = ROAD;
	m_Map[8][8] = ROAD;
}

void CMap::Fill()
{
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			if(EMPTY==m_Map[i][j])
				m_Map[i][j] = WALL;
		}
	}
}


bool CMap::IsFull()
{
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			if(EMPTY==m_Map[i][j])
				return false;
		}
	}
	return true;
}



bool CMap::IsConnect()
{
	if( !IsFull() )
	{
		return false;
	}
	else
	{
		int Steps = 0;

		int Record[10][10];
		for(int i=0;i<10;++i)
			for(int j=0;j<10;++j)
				Record[i][j] = 0;

		SPoint Point, Other;
		EDirection Direction;

		Point.x = 1;
		Point.y = 1;
		Other.x = 1;
		Other.y = 1;
		Direction = DOWN;

		while(8!=Point.x || 8!=Point.y)
		{
			if(Steps>3000)
				return false;
			else
			{
				switch(Direction)		//turn right depending on the current direction
				{
				case UP:
					{
						++Other.x;
					}break;
				case DOWN:
					{
						--Other.x;
					}break;
				case RIGHT:
					{
						++Other.y;
					}break;
				case LEFT:
					{
						--Other.y;
					}break;
				}

			
				if(ROAD==m_Map[Other.x][Other.y])		//turn right if it's available
				{
					Point.x = Other.x;
					Point.y = Other.y;
				}
				else
				{
					switch(Direction)		//unable to turn right, then try to go straight
					{
					case UP:
						{
							--Other.x;		//need to reset the Other
							--Other.y;
						}break;
					case DOWN:
						{
							++Other.x;
							++Other.y;
						}break;
					case RIGHT:
						{
							--Other.y;
							++Other.x;
						}break;
					case LEFT:
						{
							++Other.y;
							--Other.x;
						}break;
					}

					if(ROAD==m_Map[Other.x][Other.y])		//go straight if it's available
					{
						Point.x = Other.x;
						Point.y = Other.y;
					}
					else		//if unable to go straight either, turn left
					{
						switch(Direction)		
						{
						case UP:
							{
								++Other.y;		//need to reset the Other
								Direction = LEFT;
							}break;
						case DOWN:
							{
								--Other.y;
								Direction = RIGHT;
							}break;
						case RIGHT:
							{
								--Other.x;
								Direction = UP;
							}break;
						case LEFT:
							{
								++Other.x;
								Direction = DOWN;
							}break;
						}
					}
				}

				++Steps;
			}
		}
		return true;
	}	
}



bool CMap::AlongSurface()
{
	if( !IsFull() )
	{
		return false;
	}
	else
	{
		bool Surface[10][10][4];		//define the variable
		SPoint Position;		//the position of visitor in the ROAD		
		Position.x = 1;
		Position.y = 1;
		SPoint Wall;		//the position of the surface in the WALL
		Wall.x = 0;
		Wall.y = 1;
		int Direction = 2;		//the direction of the wall
		int Step = 0;

		for(int i=0;i<10;++i)		//set the surface
		{
			for(int j=0;j<10;++j)
			{
				for(int k=0;k<4;++k)
					Surface[i][j][k] = false;		//set all false firstly

				if(WALL==m_Map[i][j])
				{
					if(ROAD==m_Map[i][j-1] )//&& j>=1)		//0 for up		//because of the need of three-dimension arrary
						Surface[i][j][0] = true;
					if(ROAD==m_Map[i][j+1] )//&& j<=8)		//1 for down		//all about the "&& j<=8" is useless
						Surface[i][j][1] = true;
					if(ROAD==m_Map[i+1][j] )//&& j<=8)		//2 for right
						Surface[i][j][2] = true;
					if(ROAD==m_Map[i-1][j] )//&& j>=1)		//3 for left
						Surface[i][j][3] = true;
				}
			}
		}


		//while( !Surface[Wall.x][Wall.y][0] )		//find the original surface to start
		//{
		//	++Wall.y;
		//}
		//Position.x = Wall.x;
		//Position.y = Wall.y - 1;
		Wall.x = 0;		//set the first position of is (0,1)
		Wall.y = 1;
		Direction = 2;		//then the first direction should always be right


		while(8!=Position.x || 8!=Position.y)
		{
			if(Step>1000)		//it should not be available if unsolved within 1000 steps
				return false;
			else
			{
				switch(Direction)		//put up all the possibilities
				{
				case 0:
					{
						if(Surface[Wall.x+1][Wall.y-1][3] )//&& Wall.x<=8 && Wall.y>=1)		//only three kinds way to go 
						{	
							Wall.x = Wall.x + 1;
							Wall.y = Wall.y - 1;
							Direction = 3;
						}
						else if(Surface[Wall.x+1][Wall.y][0] )//&& Wall.x<=8)
						{
							Wall.x = Wall.x + 1;
							Wall.y = Wall.y;
							Direction = 0;
						}
						else if(Surface[Wall.x][Wall.y][2])
						{
							Wall.x = Wall.x;
							Wall.y = Wall.y;
							Direction = 2;
						}
					}break;
				case 1:		//almost the same as about
					{
						if(Surface[Wall.x-1][Wall.y+1][2] )//&& Wall.x>=1 && Wall.y<=8)
						{	
							Wall.x = Wall.x - 1;
							Wall.y = Wall.y + 1;
							Direction = 2;
						}
						else if(Surface[Wall.x-1][Wall.y][0] )//&& Wall.x>=1)
						{
							Wall.x = Wall.x - 1;
							Wall.y = Wall.y;
							Direction = 1;
						}
						else if(Surface[Wall.x][Wall.y][3])
						{
							Wall.x = Wall.x;
							Wall.y = Wall.y;
							Direction = 3;
						}
					}break;
				case 2:		//almost the same as about
					{
						if(Surface[Wall.x+1][Wall.y+1][0] )//&& Wall.x<=8 && Wall.y<=8)
						{	
							Wall.x = Wall.x + 1;
							Wall.y = Wall.y + 1;
							Direction = 0;
						}
						else if(Surface[Wall.x][Wall.y+1][2] )//&& Wall.y<=8)
						{
							Wall.x = Wall.x;
							Wall.y = Wall.y + 1;
							Direction = 2;
						}
						else if(Surface[Wall.x][Wall.y][1])
						{
							Wall.x = Wall.x;
							Wall.y = Wall.y;
							Direction = 1;
						}
					}break;
				case 3:		//almost the same as about
					{
						if(Surface[Wall.x-1][Wall.y-1][1] )//&& Wall.x>=1 && Wall.y>=1)
						{	
							Wall.x = Wall.x - 1;
							Wall.y = Wall.y - 1;
							Direction = 1;
						}
						else if(Surface[Wall.x][Wall.y-1][3] )//&& Wall.y>=1)
						{
							Wall.x = Wall.x;
							Wall.y = Wall.y - 1;
							Direction = 3;
						}
						else if(Surface[Wall.x][Wall.y][0])
						{
							Wall.x = Wall.x;
							Wall.y = Wall.y;
							Direction = 0;
						}
					}break;
				}
			}


			switch(Direction)		//find out the position by checking the Wall and it's direction
			{
			case 0:
				{
					Position.x = Wall.x;
					Position.y = Wall.y - 1;
				}break;
			case 1:
				{
					Position.x = Wall.x;
					Position.y = Wall.y + 1;
				}break;
			case 2:
				{
					Position.x = Wall.x + 1;
					Position.y = Wall.y;
				}break;
			case 3:
				{
					Position.x = Wall.x - 1;
					Position.y = Wall.y;
				}break;
			}

			++Step;
		}

		return true;
	}
}





void CMap::Save()
{
	ofstream outfile;
	outfile.open(".//Map.txt", ios::out);		//there should be double //
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			if(WALL==m_Map[j][i])
				outfile<<'0';
			else if(ROAD==m_Map[j][i])
				outfile<<'1';
		}
		outfile<<'\n';
	}
	outfile.close();
}



void CMap::Open(TCHAR * lpShortPath)
{
	ifstream infile;
	infile.open(lpShortPath, ios::in);
	if(!infile)
	{
		MessageBox(NULL, TEXT("Loadind a default map now..."), TEXT("No Map Finded"), MB_OK | MB_ICONHAND);
		//for(int i=0;i<10;++i)
		//	for(int j=0;j<10;++j)
		//		m_Map[i][j] = ROAD;

		//Frame();
		//abort();
	}
	else
	{
		char c;
		for(int i=0;i<10;++i)
		{
			for(int j=0;j<10;++j)
			{
				infile.get(c);
				if('\n'==c)
					--j;
				else if('0'==c)                       //这里假设文件中用0 1 2来表示ROAD,WALL1，TANK
					m_Map[j][i] = WALL;
				else if('1'==c)
					m_Map[j][i] = ROAD;
			}
		}
	}
	infile.close();
}




void CMap::AlgorithmToMap(int a[10][10])
{
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			if(0==a[i][j])
				m_Map[i][j] = WALL;
			else if(1==a[i][j])
				m_Map[i][j] = ROAD;

		}
	}

	Frame();
}


