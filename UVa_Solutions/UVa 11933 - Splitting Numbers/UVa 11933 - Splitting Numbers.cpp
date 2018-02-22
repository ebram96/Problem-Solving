//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<map>
#include<bitset>
//#include<tuple>
#include<cmath>
#include<cstdint>
#include<climits>
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
bool bin(string a , string b){return a > b;}
bool bin(int a , int b){return a > b;}
bool bin(ull a , ull b){return a > b;}
int main()
{
	frop
	int n , a , cnt;
	while(scanf("%d" , &n) == 1)
	{
		non
		cnt = a = 0;
		fo(y , 31)
		{
			if((1<<y)&n)
			{
				cnt++;
				if(cnt&1)a |= (1<<y);
			}
		}
		printf("%d %d\n" , a , n-a);
	}
}
