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
int n , m;
struct State
{int x , y , cost;};
bool grid[1000][1000] , dist[1000][1000];
inline bool valid(int x,int y)
{return !(x<0||x==n||y<0||y==m||grid[x][y]);}
int bfs(int sx,int sy,int ex,int ey)
{
	mset(dist,0);
	dist[sx][sy] = 1;
	queue<State>q;
	q.push({sx,sy,0});
	int x , y , cost;
	while(!q.empty())
	{
		x = q.front().x , y = q.front().y , cost = q.front().cost;
		if(x==ex&&y==ey)return cost;
		q.pop();
		fo(0,i,4)if(valid(x+dx[i],y+dy[i])&&!dist[x+dx[i]][y+dy[i]])
		{
			dist[x+dx[i]][y+dy[i]] = 1;
			q.push({x+dx[i],y+dy[i],cost+1});
		}
	}
}
int main()
{
	//readf
	int rows , bombs , row , col , sx , sy , ex , ey;
	while(scanf("%d %d",&n,&m)&&n)
	{
		mset(grid,0);
		scanf("%d",&rows);
		fo(0,i,rows)
		{
			scanf("%d %d",&row,&bombs);
			fo(0,j,bombs)
			{
				scanf("%d",&col);
				grid[row][col] = 1;
			}
		}
		scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
		printf("%d\n",bfs(sx,sy,ex,ey));
	}
}

