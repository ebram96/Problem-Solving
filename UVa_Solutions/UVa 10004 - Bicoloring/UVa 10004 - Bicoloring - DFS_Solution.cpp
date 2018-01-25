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
int n , l , u , v , sz , node , clr[200];
vi adj[200];
bool res , done[200];
void dfs(int node,int parent,bool color)
{
	if(!res)return;
	if(done[node])
	{
		if(clr[node]!=color)
			res = 0;
		return;
	}
	done[node] = 1;
	clr[node] = color;
	int sz = adj[node].size();
	fo(0,y,sz)if(adj[node][y]!=parent)
		dfs(adj[node][y],node,!color);
}
int main()
{
	//readf
	while(scanf("%d",&n)&&n)
	{
		fo(0,y,n)adj[y].clear();
		mset(clr,-1);
		mset(done,0);
		res = 1;
		scanf("%d",&l);
		fo(0,y,l)
		{
			scanf("%d %d",&u,&v);
			adj[v].pb(u);
			adj[u].pb(v);
		}
		dfs(0,-1,0);
		puts(res?"BICOLORABLE.":"NOT BICOLORABLE.");
	}
}

