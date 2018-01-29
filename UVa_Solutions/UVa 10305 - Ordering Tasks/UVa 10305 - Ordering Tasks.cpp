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
int dx[]={-1,0,1, 0};
int dy[]={ 0,1,0,-1};
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
int n , m;
vi res , adj[101];
bool clrd[101];
void dfs(int node)
{
	if(clrd[node])return;
	clrd[node] = 1;
	int sz = adj[node].size();
	fo(0,y,sz)dfs(adj[node][y]);
	res.pb(node);
}
int main()
{
	//readf
	while(scanf("%d %d",&n,&m)&&n)
	{
		fo(1,y,n+1)adj[y].clear();
		res.clear();
		int i , j;
		fo(0,y,m)
		{
			scanf("%d %d",&i , &j);
			adj[j].pb(i);
		}
		memset(clrd,0,sizeof(clrd));
		fo(1,y,n+1)dfs(y);
		printf("%d",res[0]);
		fo(1,y,n)printf(" %d",res[y]);
		puts("");
	}
}

