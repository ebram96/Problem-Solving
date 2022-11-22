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
	int t , n , m , inp , res;
	scanf("%d" , &t);
	wtm
	{
		res = 0;
		scanf("%d %d" , &n , &m);
		int po = pow(2 , n);
		//vector<int> v(po);
		//bool* v = new bool[po];
		bool v[1024];
		fo(y , po)
			v[y] = 1;
		fo(y , m)
		{
			scanf("%d" , &inp);
			v[inp-1] = 0;
		}
		for(int i = 0 , ind = 0 ; i < n ; i++ , po/=2 , ind = 0)
		{
			//vector<int> new_v(po/2);
			//bool* new_v = new bool(po/2);
			bool new_v[512];
			for(int y = 0 ; y < po ; y+=2)
				if((!v[y] && v[y+1]) || (v[y] && !v[y+1]))
				{
					res++;
					new_v[ind++] = 1;
				}
				else if(v[y] && v[y+1])new_v[ind++] = 1;
				else new_v[ind++] = 0;
			//v = new_v;
			copy(new_v , new_v+po/2 , v);
		}
		printf("%d\n" , res);
	}
}
