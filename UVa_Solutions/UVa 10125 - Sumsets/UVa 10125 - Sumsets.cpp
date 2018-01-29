//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<stdio.h>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<cstring>
#include<cmath>
#include<set>
#define INF ~(1<<31)
#define endl '\n'
#define fo(s , y , z) for(int y = s ; y < (int)z ; y++)
#define pb push_back
#define pob pop_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define lne if(line)puts("");else line =1
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pairii ;
typedef pair<ull,ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
//int dx[]={-1,0,1, 0};
//int dy[]={ 0,1,0,-1};
struct D_minus_C
{
	int d , c , res;
};
bool bin(D_minus_C &b,D_minus_C &a)
{return a.res>b.res;}
D_minus_C dc[2000000];
int n , a[1000] , sz , res , ind;
inline int bs(int v)
{
	int s = 0 , e = sz-1 , mid;
	while(s<=e)
	{
		mid = (s+e)>>1;
		if(dc[mid].res==v)return mid;
		else if(dc[mid].res>v)e = mid-1;
		else s = mid+1;
	}
	return -1;
}
inline bool valid_equation(int &ind,int &x,int &y)
{
	return a[x]!=dc[ind].c&&
			a[x]!=dc[ind].d&&
			a[y]!=dc[ind].c&&
			a[y]!=dc[ind].d;
}
int main()
{
	//readf
	while(scanf("%d",&n)&&n)
	{
		fo(0,y,n)scanf("%d",&a[y]);
		sz = 0;
		fo(0,x,n)fo(x+1,y,n)if(a[x]!=a[y])
		{
			dc[sz].c = a[y];
			dc[sz].d = a[x];
			dc[sz++].res = a[x]-a[y];
			dc[sz].c = a[x];
			dc[sz].d = a[y];
			dc[sz++].res = a[y]-a[x];
		}
		sort(dc,dc+sz,bin);
		res = ~INF;
		fo(0,x,n)fo(x+1,y,n)if(a[x]!=a[y])
		{
			ind = bs(a[x]+a[y]);
			if(ind==-1||!valid_equation(ind,x,y))continue;
			res = max(res,a[x]+a[y]+dc[ind].c);
		}
		if(res!=~INF)printf("%d\n",res);
		else puts("no solution");
	}
}

