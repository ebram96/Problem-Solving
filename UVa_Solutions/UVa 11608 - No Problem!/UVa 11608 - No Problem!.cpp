//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<map>
#include<cmath>
#include<set>
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define ull unsigned long long
#define pb push_back
#define gcu getchar_unlocked
#define wtm while(t--)
#define frop freopen("/home/ebram96/Desktop/in" , "r" , stdin);	freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
bool bin_s(string a , string b){return a > b;}
int main()
{
	frop
	int a[13] , inp , c = 1 , probs;
	while(scanf("%d" , &a[0])==1)
	{
		if(a[0]<0)break;
		fo(y , 12)scanf("%d" , &a[y+1]);
		probs = a[0];
		printf("Case %d:\n" , c++);
		fo(y , 12)
		{
			scanf("%d" , &inp);
			if(inp <= probs)
				puts("No problem! :D") , probs-=inp , probs+=a[y+1];
			else puts("No problem. :(") , probs+=a[y+1];
		}
	}
}
