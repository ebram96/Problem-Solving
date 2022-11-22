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
int n , m , res , ways[1000] , topo[1000] , ind;
vi adj[1000];
bool done[1000] , line;
void dfs(int node)
{
	if(done[node])return;
	done[node] = 1;
	int sz = adj[node].size();
	fo(0,y,sz)
		dfs(adj[node][y]);
	topo[ind++] = node;
}
int main()
{
	//readf
	while(scanf("%d",&m)==1)
	{
		for(int u = 0; u<m ; u++)
			adj[u].clear();
		for(int u = 0 , v ; u<m ; u++)
		{
			scanf("%d",&n);
			while(n--)
			{
				scanf("%d",&v);
				adj[u].pb(v);
			}
		}
		ind = res = 0;
		mset(done,0);
		mset(ways,0);
		ways[0] = 1;
		dfs(0);
		for(int i = ind-1 , sz , u ; i>=0 ; i--)
		{
			u = topo[i];
			sz = adj[u].size();
			if(!sz)res+=ways[u];
			fo(0,v,sz)
				ways[adj[u][v]] += ways[u];
		}
		lne;
		printf("%d\n",res);
	}
}

