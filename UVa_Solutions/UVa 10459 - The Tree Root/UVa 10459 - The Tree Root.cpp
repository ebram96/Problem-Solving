//It's all about what U BELIEVE
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<bitset>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#define endl '\n'
#define PI acos(-1)
#define INF ~(1<<31)
#define pb push_back
#define pob pop_back
#define wtm while(t--)
#define wnm while(n--)
#define lsone(Z) (Z&-Z)
#define modulo 1000000007
#define gcu getchar_unlocked
#define allof(Z) Z.begin(),Z.end()
#define rallof(Z) Z.rbegin(),Z.rend()
#define mset(z,v) memset(z,v,sizeof(z))
#define lne if(line)puts("");else line =1
#define fo(s,y,z) for(int y=s ; y<(int)z ; y++)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,ull> pairull;
typedef pair<int,int> pairii;
typedef vector<string> vstr;
typedef deque<int> dqint;
typedef set<ull> setull;
typedef unsigned int ui;
typedef queue<int> qint;
typedef vector<int> vi;
typedef set<int> seti;
typedef long long ll;
//int dx[]={-1,0,1, 0,-1,1, 1,-1};
//int dy[]={ 0,1,0,-1, 1,1,-1,-1};
vi adj[5001];
seti best , worst;
int mx , mn , n , mars[5001][5001];
int get_depth(int node,int p)
{
	if(~mars[node][p])return mars[node][p];
	int sz = adj[node].size() , ret = 0;
	fo(0,y,sz)if(adj[node][y]!=p)
		ret = max(ret , get_depth(adj[node][y],node));
	return mars[node][p] = 1+ret;
}
int main()
{
	//readf
	while(scanf("%d",&n)==1)
	{
		mset(mars,-1);
		int sz , v , d;
		fo(1,u,n+1)
			adj[u].clear();
		fo(1,u,n+1)
		{
			scanf("%d",&sz);
			while(sz--)
			{
				scanf("%d",&v);
				adj[u].pb(v);
				adj[v].pb(u);
			}
		}
		mn = INF , mx = 0;
		fo(1,u,n+1)
		{
			d = get_depth(u,-1);
			if(d<=mn)
			{
				if(d<mn)
					best.clear();
				mn = d;
				best.insert(u);
			}
			if(d>=mx)
			{
				if(d>mx)
					worst.clear();
				mx = d;
				worst.insert(u);
			}
		}
		printf("Best Roots  :");
		for(auto j : best)printf(" %d",j);
		printf("\nWorst Roots :");
		for(auto j : worst)printf(" %d",j);
		puts("");
	}
}

