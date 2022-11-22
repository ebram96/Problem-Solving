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
	//frop
	char s[101];
	int g;
	while(scanf("%d" , &g) == 1)
	{
		if(!g)break;
		scanf("%s" , s);
		int div = strlen(s)/g , beg = 0;
		while(g--)
			reverse(s+beg , s+beg+div) , beg+=div;
		puts(s);
	}
}
