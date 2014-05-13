//Algorithm.h

#ifndef _H_Algorithm
#define _H_Algorithm


#include<cstdlib>		//to make an random number
#include<ctime>

#include <stdio.h>		//for UnionFindSet algorithm
#include <stdlib.h>		//for UnionFindSet algorithm
#include <time.h>		//for UnionFindSet algorithm
#define SWAP(a,b,c) {c t=a;a=b;b=t;}		//for UnionFindSet algorithm



struct SPoint		//define a point struct for convenience
{
	int x;
	int y;
};


void RightDown(int a[10][10]);		//a algorithm to built a map
/*
1.only go right or down
2.an equal rate to chose right or down
3.if reaching the border, then go straight forward on the other direction
*/



void UpDownRightLeft(int a[10][10]);		//a algorithm to built a map
/*
1.can go up, down, right or left
2.an inequal rate to chose each direction, two for ++x, ++y and one for --x, --y
3.if reaching the border, then just can not go that way

4.may overboard and break off
*/



void UnionFindSet(int a[10][10]);
/*
http://hi.baidu.com/syxcs123/blog/item/0b83858e4ea826fef11f3608.html
简单介绍一下算法思想：首先把地图关键点的连结（墙），编号1-x*y*2，然后random shuffle
然后按照打乱后的次序，打通一些墙，用并查集检查是否要打通的两边是已经连通的就行了。
这种算法生成的特点是，分支数非常的多，较多短小分支，难度往往较DFS生成的简单
但效率非常高，生成1000*1000的迷宫，只要1秒（DFS生成的常数上要大一些）
但需要一个辅助的并查集数据结构，空间消耗大。
*/



#endif