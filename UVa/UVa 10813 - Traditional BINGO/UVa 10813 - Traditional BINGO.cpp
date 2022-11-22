//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<map>
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui unsigned int
#define ull unsigned long long
#define pb push_back
#define gcu getchar_unlocked
#define wtm while(t--)
using namespace std;
int main()
{
	//freopen("/home/ebram96/Desktop/in" , "r" , stdin);
	//freopen("/home/ebram96/Desktop/out" , "w" , stdout);
	int t;
	scanf("%d" , &t);
	wtm
	{
		int card[5][5] , res = 0 , inp;
		bool comp[5][5] = {0};
		fo(y , 2)fo(i , 5)scanf("%d" , &card[y][i]);
		scanf("%d %d" , &card[2][0], &card[2][1]);
		scanf("%d %d" , &card[2][3], &card[2][4]);
		for(ui y = 3 ; y < 5 ;y++)fo(i , 5)scanf("%d" , &card[y][i]);
		comp[2][2] = 1;
		card[2][2] = -1;
		fo(z , 75)
		{
			scanf("%d" , &inp);
			if(res)continue;
			if(inp >= 1 && inp <= 15)
			{
				fo(y , 5)
					if(card[y][0] == inp)
					{
						comp[y][0] = 1;
						break;
					}
			}
			else if(inp >= 16 && inp <= 30)
			{
				fo(y , 5)
					if(card[y][1] == inp)
					{
						comp[y][1] = 1;
						break;
					}
			}
			else if(inp >= 31 && inp <= 45)
			{
				fo(y , 5)
					if(card[y][2] == inp)
					{
						comp[y][2] = 1;
						break;
					}
			}
			else if(inp >= 46 && inp <= 60)
			{
				fo(y , 5)
					if(card[y][3] == inp)
					{
						comp[y][3] = 1;
						break;
					}
			}
			else if(inp >= 61 && inp <= 75)
			{
				fo(y , 5)
					if(card[y][4] == inp)
					{
						comp[y][4] = 1;
						break;
					}
			}
			if(z < 3)continue;
			bool fail;
			//horizontal
			fo(y , 5)
			{
				fail = 0;
				fo(i , 5)
					if(!comp[y][i])
					{
						fail = 1;
						break;
					}
				if(!fail)
				{
					res = z+1;
					break;
				}
			}
			if(!res)
			//vertical
			fo(y , 5)
			{
				fail = 0;
				fo(i , 5)
					if(!comp[i][y])
					{
						fail = 1;
						break;
					}
				if(!fail)
				{
					res = z+1;
					break;
				}
			}
			//diagonal 0
			if(!res)
			{
				fail = 0;
				fo(y , 5)
				{
					if(!comp[y][y])
					{
						fail = 1;
						break;
					}
				}
				if(!fail)
					res = z+1;
			}
			//diagonal 1
			if(!res)
			{
				fail = 0;
				fo(y , 5)
				{
					if(!comp[y][4-y])
					{
						fail = 1;
						break;
					}
				}
				if(!fail)
					res = z+1;
			}
		}
		printf("BINGO after %d numbers announced\n" , res);
	}
}
