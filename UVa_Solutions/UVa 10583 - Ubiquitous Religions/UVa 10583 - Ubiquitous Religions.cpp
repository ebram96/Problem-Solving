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
typedef pair<unsigned long long , unsigned long long> pairull;
typedef set<int> seti;
typedef set<unsigned long long> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//inline bool bin(string a , string b){return a > b;}
//inline bool bin(int a , int b){return a > b;}
//inline bool bin(ull a , ull b){return a > b;}
class ufds
{
private:
	int *rank , *prnt , sets;
public:
	ufds(int n)
	{
		rank = new int[n+1];
		prnt = new int[n+1];
		sets = n;
		memset(rank , 0 , (sizeof(int))*(n+1));
		fo(y , n+1)prnt[y] = y;
	}
	int findset(int x)
	{ return prnt[x] == x ? x : prnt[x] = findset(prnt[x]); }
	void joinset(int x ,int y)
	{
		int sx = findset(x) , sy = findset(y);
		if(sx != sy)
		{
			sets--;
			if(rank[sx] > rank[sy])
				prnt[sy] = sx;
			else
			{
				prnt[sx] = sy;
				if(rank[sx] == rank[sy])
					rank[sx]++;
			}
		}
	}
	int get_sets()
	{ return sets; }
};
int main()
{
	readf
	int n , m , inp0 , inp1 , c = 1;
	while(scanf("%d %d" , &n , &m))
	{
		non
		ufds s(n);
		fo(y , m)
		{
			scanf("%d %d" , &inp0 , &inp1);
			s.joinset(inp0 , inp1);
		}
		printf("Case %d: %d\n" , c++ , s.get_sets());
	}
}
