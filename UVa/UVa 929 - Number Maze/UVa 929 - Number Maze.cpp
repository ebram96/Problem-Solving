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
int dx[]={-1,0,1, 0,-1,1, 1,-1};
int dy[]={ 0,1,0,-1, 1,1,-1,-1};
int t , n , m , grid[999][999] , dist[999][999];
inline bool valid(int x,int y)
{return !(x<0||x==n||y<0||y==m);}
struct State
{
	int x , y , cost;
	inline bool operator<(const State &s)const
	{return s.cost<cost;}
};
inline int dijkstra()
{
	priority_queue<State>pq;
	pq.push({0,0,grid[0][0]});
	fo(0,x,n)fo(0,y,m)dist[x][y] = INF;
	dist[0][0] = grid[0][0];
	int x , y , cost;
	while(!pq.empty())
	{
		x = pq.top().x , y = pq.top().y , cost = pq.top().cost;
		pq.pop();
		if(x==n-1&&y==m-1)return cost;
		fo(0,i,4)if(valid(x+dx[i],y+dy[i])&&dist[x+dx[i]][y+dy[i]]>cost+grid[x+dx[i]][y+dy[i]])
		{
			pq.push({x+dx[i],y+dy[i],cost+grid[x+dx[i]][y+dy[i]]});
			dist[x+dx[i]][y+dy[i]] = cost+grid[x+dx[i]][y+dy[i]];
		}
	}
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		scanf("%d %d",&n,&m);
		fo(0,x,n)fo(0,y,m)
			scanf("%d",&grid[x][y]);
		printf("%d\n",dijkstra());
	}
}

