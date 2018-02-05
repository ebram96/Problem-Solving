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
int t , n , r , cnt , c;
int p[1000] , sz[1000], x[1000] , y[1000];
struct Edge{int from , to , weight;};
Edge e[1000000];
bool bin(Edge b,Edge a)
{return a.weight>b.weight;}
int getp(int node)
{return p[node] = (p[node]==node?node:getp(p[node]));}
void merge(int a,int b)
{
	int x = getp(a) , y = getp(b);
	if(x==y)return;
	if(sz[x]<sz[y])swap(x,y);
	sz[x]+=sz[y];
	p[y] = x;
}
int main()
{
	//readf
	int e_sz , px , py;
	double roads , rails;
	scanf("%d",&t);
	wtm
	{
		scanf("%d %d",&n,&r);
		roads = rails = 0;
		e_sz = 0 , cnt = 1;
		r*=r;
		fo(0,i,n)
		{
			sz[i] = 1 , p[i] = i;
			scanf("%d %d",&x[i],&y[i]);
		}
		fo(0,i,n)fo(i+1,j,n)
			e[e_sz++] = {i,j,(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])};
		sort(e,e+e_sz,bin);
		fo(0,i,e_sz)
		{
			px = getp(e[i].from) , py = getp(e[i].to);
			if(px==py)continue;
			if(e[i].weight>r)
			{
				rails += sqrt(e[i].weight);
				cnt++;
			}
			else roads += sqrt(e[i].weight);
			merge(px,py);
		}
		printf("Case #%d: %d %.lf %.lf\n",++c,cnt,roads,rails);
	}
}

