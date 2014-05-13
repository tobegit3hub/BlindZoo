//CMap.h

#ifndef _H_CMap
#define _H_CMap

#include<Windows.h>		//in order to use TCHAR
#include<CommDlg.h>		//for opening txt document

#include<fstream>		//to save and open text document
using namespace std;		//needed

#include"Algorithm.h"		//to use struct SPoint


enum EBlock		//define all the values of map
{EMPTY, WALL, ROAD};

enum EDirection
{UP, DOWN, RIGHT, LEFT};

class CMap		//the key: all the logic things about the map is here 
{
private:

public:
	EBlock m_Map[10][10];		//the two-deminsion array to signify the map
	bool bModify;		//indicate the status of if modify, in order to remind saving before exit

	CMap();		//initialize the data member
	~CMap();		//do nothing

	void Frame();		//ensure the map has border and the origin and terminal point
	void Fill();		//fill the EMPTY with WALL

	bool IsFull();		//try to find if there's somewhere EMPTY
	bool IsConnect();		//figure out if the map is connected, which means useful
	bool AlongSurface();		//figure out if the map is connect by moving along the surface

	void Save();		//save the map in a text, named "Map.txt" in current directory
	void Open(TCHAR * lpShortPath);		//use a common dialog to open a txt document


	void AlgorithmToMap(int a[10][10]);		//adjust the Algorithm function to the actual map
};









#endif