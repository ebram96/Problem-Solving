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
int n , m , disc[2001] , low[2001] , t , cnt;
bool same_comp[2001];
vi adj[2001] , stk;
void dfs(int node)
{
	low[node] = disc[node] = t++;
	same_comp[node] = 1;
	stk.pb(node);
	int sz = adj[node].size();
	fo(0,y,sz)
	{
		if(disc[adj[node][y]]==-1)dfs(adj[node][y]);
		if(same_comp[adj[node][y]])low[node] = min(low[node],low[adj[node][y]]);
	}
	if(low[node]==disc[node])
	{
		cnt++;
		same_comp[node] = 0;
		while(stk.back()!=node)
		{
			same_comp[stk.back()] = 0;
			stk.pob();
		}
		stk.pob();
	}
}
int main()
{
	//readf
	int u , v , type;
	while(scanf("%d %d",&n,&m)&&n)
	{
		mset(disc,-1);
		cnt = t = 0;
		fo(1,y,n+1)adj[y].clear();
		fo(0,y,m)
		{
			scanf("%d %d %d",&u,&v,&type);
			adj[u].pb(v);
			if(type==2)adj[v].pb(u);
		}
		fo(1,y,n+1)if(disc[y]==-1)
		{
			dfs(y);
			if(cnt>1)break;
		}
		puts(cnt==1?"1":"0");
	}
}

