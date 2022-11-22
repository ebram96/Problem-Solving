//It's all about what U BELIEVE
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<bitset>
#include<vector>
#include<cstring>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define endl '\n'
#define PI acos(-1)
#define INF ~(1<<31)
#define pb push_back
#define pob pop_back
#define wtm while(t--)
#define wnm while(n--)
#define MOD 1000000007
#define lsone(Z) (Z&-Z)
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
int dx[]={ 1,0};
int dy[]={ 0,1};
int t , n , w , px , py , sx , sy , ex , ey , grid[30][30];
ll mars[30][30];
char dir;
bool blocked[30][30][2];
bool valid(int x,int y)
{ return !(x==n || y==n); }
void markBlocked(int x,int y,char dir)
{
	//0 north
	//1 east
	if(dir=='N')
		blocked[x][y][0] = 1;
	else if(dir=='E')
		blocked[x][y][1] = 1;
	else if(dir=='S')
	{
		if(valid(x-1,y))
			blocked[x-1][y][0] = 1;
	}
	else if(valid(x,y-1))
		blocked[x][y-1][1] = 1;
}
ll traverse(int x,int y)
{
	if(x==ex && y==ey)
		return 1;
	if(~mars[x][y])
		return mars[x][y];
	mars[x][y] = 0;
	int nx , ny;
	fo(0,i,2)
	{
		nx = x+dx[i];
		ny = y+dy[i];
		if(valid(nx,ny) && !blocked[x][y][i])
			mars[x][y] += traverse(nx,ny);
	}
	return mars[x][y];
}
int main()
{
	//readf
	scanf("%d",&t);
	while(t--)
	{
		mset(blocked , 0);
		mset(mars , -1);
		scanf("%d%d%d%d%d%d",&n,&sx,&sy,&ex,&ey,&w);
		sx-- , sy-- , ex-- , ey--;
		swap(sx,sy);
		swap(ex,ey);
		while(w--)
		{
			scanf("%d %d %c",&px,&py,&dir);
			px-- , py--;
			swap(px,py);
			markBlocked(px,py,dir);
		}
		printf("%lld\n",traverse(sx,sy));
	}
}

