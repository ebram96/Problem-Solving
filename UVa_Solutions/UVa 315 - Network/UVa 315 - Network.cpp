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
int n , u , v , res , t , low[100] , disc[100] , root_ch;
char c;
bool mars[100] , ap[100];
seti adj[100];
void dfs(int node,int p)
{
	low[node] = disc[node] = t++;
	mars[node] = 1;
	for(auto u : adj[node])
	{
		if(u==p)continue;
		if(!mars[u])
		{
			dfs(u,node);
			if(node==1)root_ch++;
			if(disc[node]<=low[u] && ~p)
				ap[node] = 1;
			low[node] = min(low[node],low[u]);
		}
		else low[node] = min(low[node],disc[u]);
	}
}
int main()
{
	//readf
	while(scanf("%d",&n)&&n)
	{
		fo(1,y,n+1)adj[y].clear();
		while(scanf("%d",&u)&&u)
			while(scanf(" %d%c",&v,&c))
			{
				adj[u].insert(v);
				adj[v].insert(u);
				if(c=='\n')break;
			}
		res = t = root_ch = 0;
		mset(mars,0);
		mset(ap,0);
		dfs(1,-1);
		fo(1,y,n+1)res+=ap[y];
		printf("%d\n",res+(root_ch>1));
	}
}

