//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<map>
/*#include"head.h"
#include <sys/types.h>
#include <sys/stat.h>*/
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define pb push_back
#define wtm while(t--)
using namespace std;
int main()
{
	ui a , b , c , t;
	scanf("%u" , &t);
	wtm
	{
		scanf("%u %u %u" , &a , &b , &c);
		int board[101] = {0};
		int pos[1000000];
		fo(y , a)pos[y] = 1;
		//memset(pos , 1 , 3);
		while(b--)
		{
			int x;
			scanf("%d" , &x);
			scanf("%d" , &board[x]);
		}
		bool hund = 0;
		for(ui y = 0 , i = 0 , inp ; y < c ; y++)
		{
			scanf("%u" , &inp);
			if(hund)continue;
			pos[i] += inp;
			if(board[pos[i]])
				pos[i] = board[pos[i]];
			if(pos[i] == 100)hund = 1;
			i++;
			if(i == a)i = 0;
		}
		fo(y , a)
			printf("Position of player %u is %d.\n" , y+1 , pos[y]);
	}
}
