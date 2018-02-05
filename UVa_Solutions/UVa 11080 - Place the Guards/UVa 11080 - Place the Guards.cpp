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
int T , v , e , f , t , clr[200] , res , sz , size_1;
vi adj[200];
bool possible , done[200];
void bfs(qint &q,int node)
{
	int black = 0 , white = 0;
	q.push(node);
	if(clr[node]==-1)
	{
		clr[node] = !(white>black);//color the first node with the minimum color
		(clr[node]?white:black)++;
	}
	while(possible&&!q.empty())
	{
		node = q.front();
		q.pop();
		if(done[node])continue;
		done[node] = 1;
		sz = adj[node].size();
		fo(0,y,sz)
		{
			if(clr[adj[node][y]]==clr[node])
			{
				possible = 0;
				break;
			}
			q.push(adj[node][y]);
			if(~clr[adj[node][y]])continue;//already colored and counted
			clr[adj[node][y]] = !clr[node];
			(clr[adj[node][y]]?white:black)++;
		}
	}
	res+=min(black,white);
}
int main()
{
	//readf
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&v,&e);
		fo(0,y,v)adj[y].clear();
		fo(0,y,e)
		{
			scanf("%d %d",&f,&t);
			adj[f].pb(t);
			adj[t].pb(f);
		}
		qint q;
		mset(clr,-1);
		mset(done,0);
		size_1 = res = 0;
		possible = 1;
		fo(0,y,v)if(possible&&!done[y])
			if(adj[y].empty())size_1++;//a component with only one node
			else bfs(q,y);
		if(!possible)res = -1 , size_1 = 0;
		printf("%d\n",res+size_1);
	}
}

