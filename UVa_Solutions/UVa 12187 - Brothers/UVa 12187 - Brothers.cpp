//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<map>
#include<unordered_map>
//#include<bitset>
//#include<tuple>
#include<cmath>
//#include<cstdint>
#include<climits>
#include<set>
//#include<unordered_set>
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
bool bina(int a , int b){return a > b;}
bool bin(ull a , ull b){return a > b;}
int main()
{
	frop
	int n , k , r , c , a[100][100] , b[100][100];
	while(scanf("%d %d %d %d" , &n , &r , &c , &k))
	{
		non
		fo(y , r)fo(i , c)
		scanf("%d" , &a[y][i]) , b[y][i] = a[y][i];
		while(k--)
		{
			fo(y , r)fo(i , c)
			{
				if(i != c-1)
				{
					if(b[y][i+1] == b[y][i]+1)
					{
						a[y][i+1] = b[y][i];
					}
					else if(!b[y][i+1] && b[y][i] == n-1)
					{
						a[y][i+1] = b[y][i];
					}
				}
				if(i)
				{
					if(b[y][i-1] == b[y][i]+1)
					{
						a[y][i-1] = b[y][i];
					}
					else if(!b[y][i-1] && b[y][i] == n-1)
					{
						a[y][i-1] = b[y][i];
					}
				}
				if(y != r-1)
				{
					if(b[y+1][i] == b[y][i]+1)
					{
						a[y+1][i] = b[y][i];
					}
					else if(!b[y+1][i] && b[y][i] == n-1)
					{
						a[y+1][i] = b[y][i];
					}
				}
				if(y)
				{
					if(b[y-1][i] == b[y][i]+1)
					{
						a[y-1][i] = b[y][i];
					}
					else if(!b[y-1][i] && b[y][i] == n-1)
					{
						a[y-1][i] = b[y][i];
					}
				}
			}
			if(k)
			{
				fo(y , r)fo(i , c)
					b[y][i] = a[y][i];
			}
		}
		fo(y , r)
		{
			printf("%d" , a[y][0]);
			for(int i = 1 ; i < c ; i++)
				printf(" %d" , a[y][i]);
			puts("");
		}
	}
}
