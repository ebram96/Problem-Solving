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
class ufds
{
private:
	int *rank , *prnt , *sz;
public:
	ufds(int n)
	{
		rank = new int[n+1];
		prnt = new int[n+1];
		sz = new int[n+1];
		memset(rank , 0 , (sizeof(int))*(n+1));
		fo(y , n+1)prnt[y] = y , sz[y] = 1;
	}
	int findset(int x)
	{ return prnt[x] == x ? x : prnt[x] = findset(prnt[x]); }
	void joinset(int x ,int y)
	{
		int sx = findset(x) , sy = findset(y);
		if(sx != sy)
		{
			if(rank[sx] > rank[sy])prnt[sy] = sx , sz[sx]+=sz[sy];
			else
			{
				prnt[sx] = sy, sz[sy]+=sz[sx];
				if(rank[sx] == rank[sy])rank[sy]++;
			}
		}
	}
	ui get_sz(int x)
	{ return sz[findset(x)]; }
};
int main()
{
	//readf
	//writef
	int n , m , k , inp , prev;
	while(scanf("%d %d" , &n , &m))
	{
		non
		ufds s(n-1);
		seti zero;
		bool zero_in_group;
		fo(y , m)
		{
			zero_in_group = 0;
			seti temp;
			scanf("%d %d" , &k , &inp);
			if(!inp)zero_in_group = 1;
			else temp.insert(inp);
			fo(i , k-1)
			{
				prev = inp;
				scanf("%d" , &inp);
				if(!inp)zero_in_group = 1;
				else temp.insert(inp);
				s.joinset(inp , prev);
			}
			if(zero_in_group)zero.insert(temp.begin() , temp.end());
		}
		if(zero_in_group&&!zero.empty())
			for(auto j : zero)s.joinset(0 , j);
		printf("%d\n" , s.get_sz(0));
	}
}
