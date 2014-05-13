//CVisitor.cpp

#include"CVisitor.h"


CVisitor::CVisitor()
{
	m_StatusOfVisitor = true;

	m_Position.x = 1;
	m_Position.y = 1;

	m_Tool = EMPTY;
}

CVisitor::~CVisitor()
{

}


void CVisitor::EchoInfo()
{
	cout<<"["<<m_Position.x<<","<<m_Position.y<<"] : ";
}

void CVisitor::Beep()
{
	for(int i=0;i<m_Position.x;++i)		//read the Position
		cout<<'\a';
	for(int i=0;i<m_Position.x*130000000;++i)
		;		//make a interval
	for(int i=0;i<m_Position.y;++i)
		cout<<'\a';
}


RESULT CVisitor::CmdExplainer(string CmdVerb, string CmdNoun, CZoo & Zoo)		//deal with all the command
{
	if("go"==CmdVerb)
	{
		if("north"==CmdNoun || "south"==CmdNoun || "west"==CmdNoun || "east"==CmdNoun)
		{
			//if(DOOR==Zoo.m_Map[m_Position.x][m_Position.y].Tool)		//in case getting throuht the door
			//{
			//	cout<<"Here's a door. You can't get through directly!!!"<<endl;
			//	return RIGHT;
			//}


			if("north"==CmdNoun && Zoo.m_Map[m_Position.x][m_Position.y-1].Road)
			{
				Move(NORTH);
			}	
			else if("south"==CmdNoun && Zoo.m_Map[m_Position.x][m_Position.y+1].Road)
			{

				Move(SOUTH);
			}	
			else if("west"==CmdNoun && Zoo.m_Map[m_Position.x-1][m_Position.y].Road)
			{
				Move(WEST);
			}		
			else if("east"==CmdNoun && Zoo.m_Map[m_Position.x+1][m_Position.y].Road)
			{
				Move(EAST);
			}
			else
			{
				cout<<"There's a wall and you can't get through!!!"<<endl;
				return RIGHT;
			}


			//if(KEY==Zoo.m_Map[m_Position.x][m_Position.y].Tool)
			//	cout<<"Here's a key."<<endl;

			//if(DOOR==Zoo.m_Map[m_Position.x][m_Position.y].Tool)		//in case getting throuht the door
			//	cout<<"Here's a door. You can't get through directly!!!"<<endl;
			

			if(8==m_Position.x && 8==m_Position.y)
			{
				cout<<"     Haha, you go throuth the blind zoo..."<<endl
					<<"     Honestly, I really, really appreciate lives of the blind from the very first day I thought about that, don't you?"<<endl;
			}

			if(NULL!=Zoo.m_pAnimal[m_Position.x][m_Position.y])
			{
				cout<<"There's an animal here."<<endl;
			}


			if(Zoo.m_Map[m_Position.x][m_Position.y].Step)
				cout<<"OK, but you have been here ever."<<endl;

			Zoo.SetStep(m_Position.x, m_Position.y);



			return DONE;
		}
		else return WRONG;
	}


	else if("touch"==CmdVerb)
	{
		if("head"==CmdNoun || "neck"==CmdNoun || "body"==CmdNoun || "tail"==CmdNoun || "more"==CmdNoun)
		{
			if("head"==CmdNoun && NULL!=Zoo.m_pAnimal[m_Position.x][m_Position.y])		
			{
				Zoo.m_pAnimal[m_Position.x][m_Position.y]->Touch(HEAD);
			}
			else if("neck"==CmdNoun && NULL!=Zoo.m_pAnimal[m_Position.x][m_Position.y])
			{
				Zoo.m_pAnimal[m_Position.x][m_Position.y]->Touch(NECK);
			}
			else if("body"==CmdNoun && NULL!=Zoo.m_pAnimal[m_Position.x][m_Position.y])
			{
				Zoo.m_pAnimal[m_Position.x][m_Position.y]->Touch(BODY);
			}
			else if("tail"==CmdNoun && NULL!=Zoo.m_pAnimal[m_Position.x][m_Position.y])
			{
				Zoo.m_pAnimal[m_Position.x][m_Position.y]->Touch(TAIL);
			}
			else if("more"==CmdNoun && NULL!=Zoo.m_pAnimal[m_Position.x][m_Position.y])
			{
				Zoo.m_pAnimal[m_Position.x][m_Position.y]->Charateristic();
			}
			else
			{
				cout<<"Here's no animal!!!"<<endl;
				return RIGHT;
			}
			return DONE;
		}
		else return WRONG;
	}


	else if("is"==CmdVerb)
	{
		if("elephant"==CmdNoun || "giraffe"==CmdNoun || "mouse"==CmdNoun || "tiger"==CmdNoun)
		{
			if("elephant"==CmdNoun && ELEPHANT==Zoo.m_pAnimal[m_Position.x][m_Position.y]->m_Species)		
			{
				cout<<"Bingo, you're right and it's an elephant."<<endl;
			}
			else if("giraffe"==CmdNoun && GIRAFFE==Zoo.m_pAnimal[m_Position.x][m_Position.y]->m_Species)
			{
				cout<<"Bingo, you're right and it's a giraffe."<<endl;
			}
			else if("mouse"==CmdNoun && MOUSE==Zoo.m_pAnimal[m_Position.x][m_Position.y]->m_Species)
			{
				cout<<"Bingo, you're right and it's a mouse."<<endl;
			}
			else if("tiger"==CmdNoun && TIGER==Zoo.m_pAnimal[m_Position.x][m_Position.y]->m_Species)
			{
				cout<<"Bingo, you're right and it's a tiger."<<endl;
			}
			else
			{
				cout<<"Here's no animal or You guess wrong!!!"<<endl;
				return RIGHT;
			}
			return DONE;
		}
		else return WRONG;
	}


	else if("get"==CmdVerb)
	{
		if("key"==CmdNoun)
		{
			if(KEY==Zoo.m_Map[m_Position.x][m_Position.y].Tool)
			{
				m_Tool = KEY;
				Zoo.m_Map[m_Position.x][m_Position.y].Tool = EMPTY;
				cout<<"OK, now you have a key to open door."<<endl;			
			}
			else
			{
				cout<<"Sorry, there's no key here!!!"<<endl;
				return RIGHT;
			}
			return DONE;
		}
		else return WRONG;
	}

	else if("open"==CmdVerb)
	{
		if("door"==CmdNoun)
		{
			if(DOOR!=Zoo.m_Map[m_Position.x][m_Position.y].Tool)
				cout<<"There's no door here!!!"<<endl;
			else if(KEY!=m_Tool)
				cout<<"You don't have key to open the door!!!"<<endl;
			else
			{
				Zoo.m_Map[m_Position.x][m_Position.y].Tool = EMPTY;
				m_Tool = EMPTY;
				cout<<"OK, now you open the door."<<endl;
				return DONE;
			}
				
			return RIGHT;
		}
		else return WRONG;
	}

	else if("kill"==CmdVerb)
	{
		if("myself"==CmdNoun)
		{
			m_StatusOfVisitor = false;
			return DONE;
		}
		else return WRONG;
	}

	else if("crack"==CmdVerb)		//something we don't announce
	{
		if("species"==CmdNoun)
		{
			if(NULL!=Zoo.m_pAnimal[m_Position.x][m_Position.y])
			{
				Zoo.m_pAnimal[m_Position.x][m_Position.y]->Touch(SPECIES);
				return DONE;
			}
			else 
			{
				cout<<"Here's no animal!!!"<<endl;
				return RIGHT;
			}
		}


		else if("map"==CmdNoun)
		{
			for(int i=0;i<10;++i)
			{
				for(int j=0;j<10;++j)
				{
					if(Zoo.m_Map[j][i].Road)
						cout<<'1'<<' ';
					else cout<<'0'<<' ';
				}
				cout<<endl;
			}
			return DONE;
		}

		else if("animal"==CmdNoun)
		{
			for(int i=0;i<10;++i)
			{
				for(int j=0;j<10;++j)
				{
					if(NULL!=Zoo.m_pAnimal[i][j])
					{				
						cout<<"in ("<<i<<","<<j<<"), ";
						Zoo.m_pAnimal[i][j]->Touch(SPECIES);
					}
				}
			}
			return DONE;
		}

		else if("step"==CmdNoun)
		{
			Zoo.ShowStep();
			return DONE;
		}
	}

	else if("fuck"==CmdVerb)
	{
		if("you"==CmdNoun)
		{
			cout<<"Such a very word in this super unexceptionable programme!!!"<<endl
				<<"And you are not Avril Lavigne, either!!!"<<endl;
			m_StatusOfVisitor = false;
		}
		return DONE;
	}

	else if("man"==CmdVerb)
	{
		if("man"==CmdNoun || "go"==CmdNoun || "touch"==CmdNoun || "is"==CmdNoun || "get"==CmdNoun || "open"==CmdNoun || "kill"==CmdNoun)
		{
			if("man"==CmdNoun)
				cout<<"In linux, man(for manual) can let you know the commands, here are examples..."<<endl
				    <<"man go : to see more usage of command go."<<endl
					<<"man touch : to see more usage of command touch."<<endl
					<<"man is : to see more usage of command is."<<endl
					<<"man open : to see more usage of command open."<<endl
					<<"man kill : to see more usage of command kill."<<endl<<endl;
			else if("go"==CmdNoun)
				cout<<"You can move and change the coordinate correspondingly, here are examples..."<<endl
				    <<"go north : to go to the north and make y minus one."<<endl
					<<"go south : to go to the south and make y plus one."<<endl
					<<"go west : to go to the west and make x minus one."<<endl
					<<"go east : to go to the east and make x plus one."<<endl<<endl;
			else if("touch"==CmdNoun)
				cout<<"You can touch parts of animal and get some information, here are examples..."<<endl
				    <<"touch head : to figure out what it's head look like."<<endl
					<<"touch neck : to figure out what it's neck look like."<<endl
					<<"touch body : to figure out what it's body look like."<<endl
					<<"touch tail : to figure out what it's tail look like."<<endl
					<<"touch more : to figure out what it's most special feature."<<endl<<endl;
			else if("is"==CmdNoun)
				cout<<"You can guess what the animal it is, here are examples......"<<endl
				    <<"is elephant : guess that animal is elephant if you're sure."<<endl
					<<"is giraffe : guess that animal is giraffe if you're sure."<<endl
					<<"is mouse : guess that animal is mouse if you're sure."<<endl
					<<"is tiger : guess that animal is tiger if you're sure."<<endl<<endl;
			else if("get"==CmdNoun)
				cout<<"You can get the key for opening the door, here are examples......"<<endl
				    <<"get key : to pick the key if there's a key but recently this command is banned!!!"<<endl<<endl;
			else if("open"==CmdNoun)
				cout<<"You can open the door with your key, here are examples......"<<endl
				    <<"open door : to open the door if there's a key and a door but recently this command is banned!!!"<<endl<<endl;
			else if("kill"==CmdNoun)
				cout<<"It can end the journey before you get to exit, here are examples......"<<endl
				    <<"kill myself : you know it means commit suicide and quit the program now."<<endl<<endl;
			
			return DONE;
		}
		else return WRONG;
	}

	else return WRONG;	
}


void CVisitor::Move(EDirection Direction)
{
	switch(Direction)
	{
	case NORTH:
		{
			m_Position.y--;
		}break;
	case SOUTH:
		{
			m_Position.y++;
		}break;
	case WEST:
		{
			m_Position.x--;
		}break;
	case EAST:
		{
			m_Position.x++;
		}break;
	}

}



