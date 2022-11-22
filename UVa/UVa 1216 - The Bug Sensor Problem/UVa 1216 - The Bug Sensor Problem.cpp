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
	ll u , v , w;
	inline bool operator<(Edge &e)const
	{return e.w>w;}
};
Edge e[1000000];
int p[1000];
ll x[1000] , y[1000] , res;
int getp(int x)
{return p[x] == x ? x : p[x] = getp(p[x]);}
void merge(int a , int b)
{
	int x = getp(a) , y = getp(b);
	if(x==y)return;
	p[y] = x;
}
int main()
{
	//readf
	int t , s , n , e_sz , pu , pv;
	scanf("%d",&t);
	wtm
	{
		scanf("%d",&s);
		n = e_sz = res = 0;
		while(scanf("%lld",&x[n])&&~x[n])
		{
			scanf("%lld",&y[n]);
			int ind = n-1;
			while(ind>=0)
				e[e_sz++] = {ind,n,(x[ind]-x[n])*(x[ind]-x[n])+(y[ind]-y[n])*(y[ind--]-y[n])};
			n++;
		}
		fo(0,i,n)p[i] = i;
		sort(e,e+e_sz);
		fo(0,i,e_sz)
		{
			pu = getp(e[i].u) , pv = getp(e[i].v);
			if(pv==pu)continue;
			merge(pv,pu);
			res = max(res,e[i].w);
			n--;
			if(n==s)break;
		}
		printf("%.lf\n",ceil(sqrt(res)));
	}
}

