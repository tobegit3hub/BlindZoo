//CVisitor

#ifndef _H_CVisitor
#define _H_CVisitor

#include"afx.h"
#include"CZoo.h"		//should access Zoo as reference

class CVisitor
{
private:

public:
	bool m_StatusOfVisitor;		//indicate the status of the visitor
	SPoint m_Position;		//show the position of visitor by pointing out x and y
	string m_CmdVerb, m_CmdNoun;		//the commands which are get from user's input

	ETool m_Tool;		////////////////////////door and key make it complicated, so it's useless now


	CVisitor();		//initial the data member
	~CVisitor();		//do nothing

	void EchoInfo();		//cout the x and y of position
	void Beep();		//make a noise to remind user of his or her position

	void Move(EDirection Direction);		//take a step by different direction

	RESULT CmdExplainer(string CmdVerb, string CmdNoun, CZoo & Zoo);		//the key of program: explain and react different commands

};



#endif