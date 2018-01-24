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
int n , m , ways[1000];
vi adj[1000];
bool line;
int rec(int node)
{
	if(ways[node])return ways[node];
	int sz = adj[node].size() , &ret = ways[node];
	fo(0,y,sz)
		ret+=rec(adj[node][y]);
	return ret;
}
int main()
{
	//readf
	while(scanf("%d",&m)==1)
	{
		for(int u = 0; u<m ; u++)
			adj[u].clear();
		mset(ways,0);
		for(int u = 0 , v ; u<m ; u++)
		{
			scanf("%d",&n);
			if(!n)ways[u] = 1;
			while(n--)
			{
				scanf("%d",&v);
				adj[u].pb(v);
			}
		}
		lne;
		printf("%d\n",rec(0));
	}
}

