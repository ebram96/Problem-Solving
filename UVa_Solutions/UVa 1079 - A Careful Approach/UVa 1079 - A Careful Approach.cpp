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
int n , c = 1;
pairii p[8];
bool chk(int x)
{
	int t = p[0].first;
	for(int y = 1 ; y < n ; y++)
	{
		if(t+x>p[y].second)return 0;
		t+=x;
		if(t<p[y].first)t = p[y].first;
	}
	return 1;
}
int main()
{
	readf
	while(scanf("%d" , &n))
	{
		non
		fo(y , n)
		{
			scanf("%d %d" , &p[y].first , &p[y].second);
			p[y].first*=60000 , p[y].second*=60000;
		}
		if(n==1)
		{
			printf("Case %d: 0:00\n" , c++);
			continue;
		}
		sort(p , p+n);
		int res = -1;
		do
		{
			int s = 0 , e = 1440*60000 , mid;
			while(s<=e)
			{
				mid = s+(e-s)/2;
				if(chk(mid))res = max(res , mid) , s = mid+1;
				else e = mid-1;
			}
		}while(next_permutation(p , p+n));
		if(res%1000>=500)res/=1000 , res++;
		else res/=1000;
		printf("Case %d: %d:%.2d\n" , c++ , res/60 , res%60);
	}
}
