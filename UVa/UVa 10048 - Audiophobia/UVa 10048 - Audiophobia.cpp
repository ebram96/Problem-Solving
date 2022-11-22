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
struct TreeEdge
{int v , w;};
struct Edge
{
	int u , v , w;
	inline bool operator<(Edge &e)const
	{return e.w>w;}
};
int C , S , Q , p[101] , c , cnt;
bool line;
Edge e[10000];
int getp(int x)
{return p[x]==x?x:p[x] = getp(p[x]);}
void merge(int a,int b)
{
	int x = getp(a) , y = getp(b);
	if(x==y)return;
	p[y] = x;
}
vector<TreeEdge> adj[101];
int tolerance , dest;
void dfs(int node,int parent,int w)
{
	if(node==dest)
	{
		tolerance = w;
		return;
	}
	int sz = adj[node].size();
	fo(0,y,sz)if(adj[node][y].v!=parent)
		dfs(adj[node][y].v,node,max(w,adj[node][y].w));
}
int main()
{
	//readf
	int u , v , pu , pv;
	while(scanf("%d %d %d",&C,&S,&Q)&&C)
	{
		cnt = 0;
		fo(1,y,C+1)p[y] = y , adj[y].clear();
		fo(0,y,S)scanf("%d %d %d",&e[y].u,&e[y].v,&e[y].w);
		sort(e,e+S);
		fo(0,y,S)
		{
			pu = getp(e[y].u) , pv = getp(e[y].v);
			if(pu==pv)continue;
			merge(pu,pv);
			adj[e[y].u].pb({e[y].v,e[y].w});
			adj[e[y].v].pb({e[y].u,e[y].w});
			cnt++;
			if(cnt==C-1)break;
		}
		lne;
		printf("Case #%d\n",++c);
		fo(0,y,Q)
		{
			scanf("%d %d",&u,&v);
			pu = getp(u) , pv = getp(v);
			if(pu!=pv)puts("no path");
			else
			{
				dest = v;
				dfs(u,-1,-INF);
				printf("%d\n",tolerance);
			}
		}
	}
}

