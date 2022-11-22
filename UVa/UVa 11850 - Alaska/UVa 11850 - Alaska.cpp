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
#define non if(!n)break;
#define frop freopen("/home/ebram96/Desktop/in" , "r" , stdin);	freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
bool bin_s(string a , string b){return a > b;}
int main()
{
	frop
	int n , a[1424];
	bool res;
	while(scanf("%d" , &n))
	{
		if(!n)break;
		res = 1;
		fo(y , n)scanf("%d" , &a[y]);
		sort(a , a+n);
		a[n] = 1422;
		for(int y = 1 ; y <= n ; y++)
			if(a[y] - a[y-1] > 200)
			{
				res = 0;
				break;
			}
		if(a[n-1] < 1322)res = 0;
		puts(res ? "POSSIBLE" : "IMPOSSIBLE");
	}
}
