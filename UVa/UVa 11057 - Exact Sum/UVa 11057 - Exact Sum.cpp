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
	//readf
	int n , resx , resy , a[10000] , m;
	ui diff;
	bool line = 0;
	while(scanf("%d" , &n)==1)
	{
		diff = -1;
		fo(y , n)scanf("%d" , &a[y]);
		scanf("%d" , &m);
		sort(a , a+n);
		fo(y , n)for(int i = y+1 ; (i < n)&&(a[i]+a[y]<=m) ; i++)
			if((a[i]+a[y]==m)&&(a[i]-a[y]<diff))
				resx = a[y] , resy = a[i];
		lne
		printf("Peter should buy books whose prices are %d and %d.\n" , resx , resy);
	}
	puts("");
}
