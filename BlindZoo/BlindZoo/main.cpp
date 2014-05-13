//main.cpp

#include"CZoo.h"
#include"CVisitor.h"





int main()
{
	CZoo Zoo;
	CVisitor Visitor;
	Zoo.EchoInfo();

	while(Visitor.m_StatusOfVisitor)
	{
		Visitor.EchoInfo();
		
		getline(cin, Visitor.m_CmdVerb, ' ');
		getline(cin, Visitor.m_CmdNoun, '\n');


		RESULT eCmd = Visitor.CmdExplainer(Visitor.m_CmdVerb, Visitor.m_CmdNoun, Zoo);
		if(DONE==eCmd)
		{
			Visitor.Beep();
		}
		else if(WRONG==eCmd)
		{
			cout<<"Sorry, I Don't Get It!!!"<<endl;
		}


		




	}





	system("Pause");
	return 0;
}










