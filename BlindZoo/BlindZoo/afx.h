//afx.h

#ifndef _H_afx
#define _H_afx

#include<iostream>
#include<cstring>		//to complete command's input and compare
#include<string>
using namespace std;




enum ETool		////////////////////////////////door make it complicated, so it's useless now
{KEY, DOOR, EMPTY};

enum EDirection		//define different direction for moving
{NORTH, SOUTH, WEST, EAST};


enum EOrgan		//define different parts of animal for touching
{SPECIES, HEAD, NECK, BODY, TAIL};

enum ESpecies		//all available kinds of animal
{DEFSPECIES, ELEPHANT, GIRAFFE, MOUSE, TIGER};

enum EHead		//different kinds of head
{DEFHEAD, BIGHEAD, SMALLHEAD};

enum ENeck		//different kinds of neck
{DEFNECK, LONGNECK, SHORTNECK, NONECK};

enum EBody		//different kinds of body
{DEFBODY, STRONGBODY, THINBODY};

enum ETail		//different kinds of tail
{DEFTAIL, LONGTAIL, SHORTTAIL, NOTAIL};


enum RESULT		//defferent result of between user's input and available command
{WRONG, RIGHT, DONE};


struct SPoint		//to express point conveniently
{
	int x;
	int y;
};

struct SBlock		//some components of the map
{
	bool Road;
	bool Step;
	ETool Tool;

};





#endif