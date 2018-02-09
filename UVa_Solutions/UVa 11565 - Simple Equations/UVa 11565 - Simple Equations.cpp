//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<cstdint>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<cstring>
#include<cmath>
#include<unordered_map>
#include<climits>
#include<set>
#include<unordered_set>
#define endl '\n'
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define lne if(line)puts("");else line = 1;
#define pb push_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define non if(!n)break;
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//inline bool bin(string a , string b){return a > b;}
//inline bool bin(int a , int b){return a > b;}
//inline bool bin(ull a , ull b){return a > b;}
int main()
{
	readf
	int a , b , c , t;
	scanf("%d" , &t);
	bool res;
	wtm
	{
		scanf("%d %d %d" , &a , &b , &c);
		res = 0;
		for(int x = -100 ; x < a ; x++)
			for(int y = -98 ; x + y < a ; y++)
				for(int z = 1 ; x*x + y*y + z*z <= c ; z++)
					if((x+y+z==a)&&(x*y*z==b)&&(x*x+y*y+z*z==c) && x != y && x != z && z != y)
						printf("%d %d %d\n" , x , y , z) , res = 1 , x = c+1;
		if(!res)puts("No solution.");
	}
}
