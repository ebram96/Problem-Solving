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
struct State
{
	int level , elev , cost;
	inline bool operator<(const State &s)const
	{return s.cost==cost?s.level>level:s.cost<cost;}
};
bool adj_elev[5][100];
bool adj_level[100][5];
int t[5] , n , k , dist[100][5];
int dijkstra()
{
	fo(0,y,100)fo(0,i,n)
		dist[y][i] = INF;
	priority_queue<State> pq;
	fo(0,y,n)if(adj_elev[y][0])
		pq.push({0,y,0});
	int level , elev , cost;
	while(!pq.empty())
	{
		level = pq.top().level , elev = pq.top().elev , cost = pq.top().cost;
		if(level==k)return cost;
		pq.pop();
		if(dist[level][elev]!=INF)
		{
			dist[level][elev] = min(dist[level][elev],cost);
			continue;
		}
		dist[level][elev] = min(dist[level][elev],cost);
		//change
		fo(0,y,n)if(adj_level[level][y]&&y!=level)
			pq.push({level,y,cost+60});
		//keep
		fo(0,y,100)if(adj_elev[elev][y]&&y!=level)
		{
			if(y>level)
				pq.push({y,elev,cost+(y-level)*t[elev]});
			else
				pq.push({y,elev,cost+(level-y)*t[elev]});
		}
	}
	return -1;
}
int main()
{
	//readf
	char c;
	int level,res;
	while(scanf("%d %d",&n,&k)==2)
	{
		fo(0,y,n)scanf("%d",&t[y]);
		mset(adj_elev ,0);
		mset(adj_level,0);
		fo(0,elev,n)
			while(scanf("%d",&level))
			{
				adj_level[level][elev] = adj_elev[elev][level] = 1;
				if(scanf("%c",&c)!=1||c!=' ')break;
			}
		res = dijkstra();
		if(~res)printf("%d\n",res);
		else puts("IMPOSSIBLE");
	}
}

