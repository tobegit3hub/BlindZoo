//Algorithm

#include"Algorithm.h"



void RightDown(int a[10][10])
{
	

	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
			a[i][j] = 0; 

	SPoint Point;
	Point.x = 1;
	Point.y = 1;


	while(8!=Point.x || 8!=Point.y)
	{
		a[Point.x][Point.y] = 1;

		int res = rand() % 2;
		switch(res)
		{
		case 0:
			{
				if(Point.x<8)
					++Point.x;
			}break;
		case 1:
			{
				if(Point.y<8)
					++Point.y;
			}break;
		}
	}

	a[Point.x][Point.y] = 1;
}








void UpDownRightLeft(int a[10][10])
{
	

	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
			a[i][j] = 0; 

	SPoint Point;
	Point.x = 1;
	Point.y = 1;


	while(8!=Point.x || 8!=Point.y)
	{
		a[Point.x][Point.y] = 1;

		int res = rand() % 6;
		switch(res)
		{
		case 0:
			{
				if(Point.y>1)
					--Point.y;
			}break;
		case 1:
		case 2:
			{
				if(Point.y<8)
					++Point.y;
			}break;
		case 3:
		case 4:
			{
				if(Point.x<8)
					++Point.x;
			}break;
		case 5:
			{
				if(Point.y>1)
					--Point.x;
			}break;
		}
	}

	a[Point.x][Point.y] = 1;
}








int uf[9000000], Map[3000][3000]; //并查集表，迷宫地图
struct PT{int x; int y;}que[5000000]; //生成序列
//int x=10,y=8,xy=0; //x,y指定要生成的大小
int x=4,y=4,xy=0; //x,y指定要生成的大小				//crack: make x and y equal to 4

int findP(int& n)
{
    int a=++n;
    while (uf[a]) a=uf[a];
    if (a!=n) uf[n] = a;
    return n=a;
}

int Ins(PT xy)
{
    int a=(xy.y-1)/2*x+(xy.x-1)/2, b=(xy.y&1)?a+1:a+x;
    if (findP(a)!=findP(b)) {uf[b] = a; return 1;}
    return 0;
}

void UnionFindSet(int a[10][10])
{
	x=4,y=4,xy=0;
	for(int i=0;i<9000000;++i)
		uf[i] = 0;
	for(int i=0;i<3000;++i)
		for(int j=0;j<3000;++j)
			Map[i][j]= 0 ;
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
			Map[i][j] = 0;


    int n=0,_y,_x,o;
    //srand(time(NULL)); 
	Map[1][0]=Map[y*2-1][x*2]=1;
    for (_y=1; o=_y!=y,_y<=y; ++_y)
        for (_x=1; _x<=x; ++_x)
        {
            if (_x<x)que[n].y = _y*2-1, que[n].x = _x*2,++n;
             if (o)que[n].y = _y*2, que[n].x = _x*2-1,++n;
        }
    for (xy=n,n=0; n<xy; ++n) {int z=rand()%xy; SWAP(que[n],que[z],PT);}
    for (n=0; n<xy; ++n)
    {
        if (!Ins(que[n])) continue;
        Map[que[n].y][que[n].x] = 1;
        if (que[n].y&1) Map[que[n].y][que[n].x-1] = Map[que[n].y][que[n].x+1] = 1;
        else Map[que[n].y-1][que[n].x] = Map[que[n].y+1][que[n].x] = 1;
     }
    for (_y=0; _y<=y*2; ++_y)
    {
        for (_x=0; _x<=x*2; ++_x)
            //if (Map[_y][_x]) fputs("　", stdout); else fputs("█", stdout);
			 if (Map[_y][_x]) a[_y][_x]=1; else a[_y][_x]=0;		//crack: make it into what I want
        putchar(10);
    }




    
}