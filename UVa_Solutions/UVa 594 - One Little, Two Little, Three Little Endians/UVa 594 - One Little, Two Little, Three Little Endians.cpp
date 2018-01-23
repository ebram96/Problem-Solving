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

	//frop
	int inp , t;
	while(scanf("%d" , &inp) == 1)
	{
		t = inp;
		int rev = 0;
		bool a[4][8];
		fo(y , 4)
		{
			fo(i , 8)
				a[y][7-i] = ((1<<i)&inp);
			inp >>=8;
		}
		fo(y , 4)
			fo(i , 8)
			{
				rev<<=1;
				rev |= a[y][i];
			}
		printf("%d converts to %d\n" , t , rev);
	}
}
