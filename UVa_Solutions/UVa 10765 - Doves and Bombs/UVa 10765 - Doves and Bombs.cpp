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
struct Station{int node,cnt;};
vector<Station>res;
bool bin(Station b,Station a)
{return a.cnt==b.cnt?a.node>b.node:a.cnt<b.cnt;}
int n , m , disc[10000] , low[10000] , t , root_ch;
bool mars[10000] , ap[10000];
vi adj[10000];
void dfs(int node,int parent = -1)
{
	low[node] = disc[node] = t++;
	mars[node] = 1;
	int sz = adj[node].size() , cnt = 0;
	fo(0,y,sz)
	{
		if(adj[node][y]==parent)continue;
		if(!mars[adj[node][y]])
		{
			if(!node)root_ch++;
			dfs(adj[node][y],node);
			if(disc[node]<=low[adj[node][y]])
			{
				if(~parent)ap[node] = 1;
				cnt++;
			}
			low[node] = min(low[node],low[adj[node][y]]);
		}
		else low[node] = min(low[node],disc[adj[node][y]]);
	}
	if(root_ch>1&&!node)ap[node] = 1 , cnt--;
	if(ap[node])res.pb({node,cnt+1});
}
int main()
{
	//readf
	int u , v;
	while(scanf("%d %d",&n,&m)&&n)
	{
		fo(0,y,n)adj[y].clear();
		while(scanf("%d %d",&u,&v)&&~u)
		{
			adj[u].pb(v);
			adj[v].pb(u);
		}
		mset(ap,0);
		mset(mars,0);
		res.clear();
		t = root_ch = 0;
		dfs(0);
		sort(allof(res),bin);
		int sz = min(int(res.size()),m);
		fo(0,y,sz)printf("%d %d\n",res[y].node,res[y].cnt);
		for(int y = 0 ; y<n && sz<m ; y++)if(!ap[y])
			printf("%d 1\n",y),sz++;
		puts("");
	}
}

