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
int t , n , u , v , mx , d[50001] , res , tc , adj[50001] , cyc_sz;
stack<int> path , cyc , clr;
bool mars[50001];
int dfs(int node)
{
	if(d[node])return d[node];
	if(mars[node])
	{
		while(path.top()!=node)
			cyc.push(path.top()) , path.pop();
		cyc.push(path.top()) , path.pop();
		return 0;
	}
	mars[node] = 1;
	path.push(node);
	return d[node] = 1+dfs(adj[node]);
}
int main()
{
	//readf
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		fo(0,y,n)
		{
			scanf("%d %d",&u,&v);
			adj[u] = v;
		}
		res = 0 , mx = -INF;
		mset(d,0);
		mset(mars,0);
		fo(1,y,n+1)if(!mars[y])
		{
			path = cyc = clr;
			dfs(y);
			cyc_sz = cyc.size();
			while(!cyc.empty())
			{
				d[cyc.top()] = cyc_sz;
				path.push(cyc.top());
				cyc.pop();
			}
			while(!path.empty())
			{
				if(d[path.top()]>mx)
				{
					mx = d[path.top()];
					res = path.top();
				}
				else if(d[path.top()]==mx)
					res = min(res , path.top());
				path.pop();
			}
		}
		printf("Case %d: %d\n",++tc,res);
	}
}

