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
struct Edge{int from,to;};
vector<Edge> links;
bool bin(Edge b,Edge a)
{return a.from!=b.from?a.from>b.from:a.to>b.to;}
seti adj[10001];//no idea of its size
bool mars[10001];
int n , desc[10001] , low[10001] , t , a , b;
void dfs(int node,int parent)
{
	desc[node] = low[node] = t++;
	mars[node] = 1;
	for(auto u : adj[node])
	{
		//int u = *s;
		if(u==parent)continue;
		if(!mars[u])
		{
			dfs(u,node);
			if(desc[node]<low[u])
			{
				a = node , b = u;
				if(a>b)swap(a,b);
				links.pb({a,b});
			}
			low[node] = min(low[node] , low[u]);
		}
		else low[node] = min(low[node] , desc[u]);
	}
}
int main()
{
	//readf
	int v , u , e;
	while(scanf("%d",&n)==1)
	{
		fo(0,y,n)adj[y].clear();
		links.clear();
		mset(mars,0);
		t = 0;
		fo(0,y,n)
		{
			scanf(" %d (%d)",&v,&e);
			while(e--)
			{
				scanf("%d",&u);
				adj[v].insert(u);
				adj[u].insert(v);
			}
		}
		fo(0,y,n)if(!mars[y])
			dfs(y,-1);
		sort(allof(links),bin);
		int sz = links.size();
		printf("%u critical links\n",sz);
		fo(0,y,sz)printf("%d - %d\n",links[y].from,links[y].to);
		puts("");
	}

}

