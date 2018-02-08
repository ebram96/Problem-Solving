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
int n , m , c , p[1000];
ui mars[1000][1000];
struct State
{
	int u , fuel;
	ui cost;
	inline bool operator<(const State &s)const
	{return s.cost<cost;}
};
struct Edge
{int v , w;};
vector<Edge>adj[1000];
int Dijkstra(int source,int destination)
{
	mset(mars,-1);
	priority_queue<State> pq;
	pq.push({source,0,0});
	int u , fuel , sz; ui cost;
	while(!pq.empty())
	{
		u = pq.top().u , fuel = pq.top().fuel , cost = pq.top().cost;
		pq.pop();
		if(u==destination)return cost;
		if(mars[u][fuel]!=ui(-1))
		{
			mars[u][fuel] = min(mars[u][fuel],cost);
			continue;
		}
		mars[u][fuel] = min(mars[u][fuel],cost);
		for(int y = 1 ; y+fuel<=c ; y++)
			pq.push({u,y+fuel,ui(y*p[u]+cost)});
		sz = adj[u].size();
		fo(0,y,sz)if(fuel>=adj[u][y].w)
			pq.push({adj[u][y].v,fuel-adj[u][y].w,cost});
	}
	return -1;
}
int main()
{
	//readf
	int u , v , w , q , res;
	while(scanf("%d %d",&n,&m)==2)
	{
		fo(0,y,n)
		{
			adj[y].clear();
			scanf("%d",&p[y]);
		}
		fo(0,y,m)
		{
			scanf("%d %d %d",&u,&v,&w);
			adj[u].pb({v,w});
			adj[v].pb({u,w});
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d %d %d",&c,&u,&v);
			res = Dijkstra(u,v);
			if(~res)printf("%d\n",res);
			else puts("impossible");
			//printf("%d\n",res);
		}
	}
}

