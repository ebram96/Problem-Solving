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
int T , s , t , n , m , dist[20000] , c;
struct State
{
	int u , w;
	inline bool operator<(const State &s)const
	{return s.w<w;}
};
struct Edge
{int v , w;};
vector<Edge> adj[20000];
inline int dijkstra()
{
	priority_queue<State>pq;
	pq.push({s,0});
	fo(0,y,n)dist[y] = INF;
	dist[s] = 0;
	int sz , u , v , w;
	while(!pq.empty())
	{
		u = pq.top().u , w = pq.top().w;
		if(u==t)return w;
		pq.pop();
		sz = adj[u].size();
		fo(0,y,sz)
		{
			v = adj[u][y].v;
			if(dist[v]>w+adj[u][y].w)
			{
				dist[v] = w+adj[u][y].w;
				pq.push({v,w+adj[u][y].w});
			}
		}
	}
	return -1;
}
int main()
{
	//readf
	int u , v , w , res;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d",&n,&m,&s,&t);
		fo(0,y,n)adj[y].clear();
		fo(0,y,m)
		{
			scanf("%d %d %d",&u,&v,&w);
			adj[u].pb({v,w});
			adj[v].pb({u,w});
		}
		res = dijkstra();
		if(~res)printf("Case #%d: %d\n",++c,res);
		else printf("Case #%d: unreachable\n",++c);
	}
}

