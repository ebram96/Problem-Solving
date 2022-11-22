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
{
	int u , v , w;
	inline bool operator<(Edge &e)const
	{return e.w>w;}
};
Edge e[1000000];
int n , m , p[1000000];
int getp(int x)
{return p[x] == x ? x : p[x] = getp(p[x]);}
inline void merge(int a,int b)
{
	int x = getp(a) , y = getp(b);
	if(x==y)return;
	p[y] = x;
}
int main()
{
	//readf
	int pu , pv , res , cnt;
	while(scanf("%d %d",&n,&m)&&n)
	{
		res = ~INF , cnt = 0;
		fo(0,y,n)p[y] = y;
		fo(0,y,m)scanf("%d %d %d",&e[y].u,&e[y].v,&e[y].w);
		sort(e,e+m);
		fo(0,y,m)
		{
			pu = getp(e[y].u) , pv = getp(e[y].v);
			if(pu == pv)continue;
			res = max(res,e[y].w);
			merge(pu,pv);
			cnt++;
			if(cnt==n-1)break;
		}
		if(cnt==n-1)printf("%d\n",res);
		else puts("IMPOSSIBLE");
	}
}

