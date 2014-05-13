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
�򵥽���һ���㷨˼�룺���Ȱѵ�ͼ�ؼ�������ᣨǽ�������1-x*y*2��Ȼ��random shuffle
Ȼ���մ��Һ�Ĵ��򣬴�ͨһЩǽ���ò��鼯����Ƿ�Ҫ��ͨ���������Ѿ���ͨ�ľ����ˡ�
�����㷨���ɵ��ص��ǣ���֧���ǳ��Ķ࣬�϶��С��֧���Ѷ�������DFS���ɵļ�
��Ч�ʷǳ��ߣ�����1000*1000���Թ���ֻҪ1�루DFS���ɵĳ�����Ҫ��һЩ��
����Ҫһ�������Ĳ��鼯���ݽṹ���ռ����Ĵ�
*/



#endif