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
struct Edge
{int u , v , w;};
Edge e[40000];
int n , m , b[201] , dist[201] , c , res , q , d;
inline int bf(int d)
{
	fo(1,y,n+1)dist[y] = 1e8;
	dist[1] = 0;
	fo(0,y,n-1)fo(0,i,m)if(dist[e[i].u]!=1e8)
		if(dist[e[i].v]>dist[e[i].u]+e[i].w)
			dist[e[i].v] = dist[e[i].u]+e[i].w;
	fo(0,i,m)if(dist[e[i].u]!=1e8)
		if(dist[e[i].v]>dist[e[i].u]+e[i].w)
			dist[e[i].v] = -1e8;
	if(dist[d]==1e8)dist[d] = 0;// < 3
	return dist[d];
}
int main()
{
	//readf
	while(scanf("%d",&n)==1)
	{
		fo(0,y,n)scanf("%d",&b[y+1]);
		scanf("%d",&m);
		fo(0,y,m)
		{
			scanf("%d %d",&e[y].u,&e[y].v);
			e[y].w = (b[e[y].v]-b[e[y].u])*(b[e[y].v]-b[e[y].u])*(b[e[y].v]-b[e[y].u]);
		}
		printf("Set #%d\n",++c);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&d);
			res = bf(d);
			if(res<3)puts("?");
			else printf("%d\n",res);
		}
	}
}

