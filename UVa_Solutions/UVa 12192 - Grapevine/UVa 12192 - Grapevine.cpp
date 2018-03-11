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
#define endl '\n'
#define fo(s , y , z) for(int y = s ; y < (int)z ; y++)
#define lne if(line)puts("");else line = 1;
#define pb push_back
#define pob pop_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
int n , m , a[500][500] , res , q , l , r;
int getcol(int &row)
{
	int lo  = 0, hi = m-1 , mid;
	while(lo<hi)
	{
		mid = (lo+hi)>>1;
		if(a[row][mid]>=l)hi=mid;
		else lo = mid+1;
	}
	return a[row][hi]<l||a[row][hi]>r?-1:hi;
}
struct Position{int x , y;};
bool equal(Position &a,Position &b)
{return a.x==b.x&&a.y==b.y;}
int diagonal(int lx,int ly,int rx,int ry)
{
	Position lo , hi , mid , prev_lo , prev_hi;
	lo.x = lx , lo.y = ly , hi.x = rx , hi.y = ry;
	prev_lo.x = -1;
	while(!(equal(lo,prev_lo)&&equal(hi,prev_hi)))
	{
		mid.x = (hi.x+lo.x)>>1;
		mid.y = (hi.y+lo.y)>>1;
		prev_lo = lo , prev_hi = hi;
		if(a[mid.x][mid.y]>r)
		{
			hi.x = mid.x-1;
			hi.y = mid.y-1;
		}
		else
		{
			lo.x = mid.x+1;
			lo.y = mid.y+1;
		}
	}
	if(a[hi.x][hi.y]<=r)return hi.x-lx+1;
	return lo.x-lx+1;
}
int main()
{
	//readf
	while(scanf("%d %d",&n,&m)&&n)
	{
		fo(0,x,n)fo(0,y,m)
			scanf("%d",&a[x][y]);
		scanf("%d",&q);
		while(q--)
		{
			res = 0;
			scanf("%d %d",&l,&r);
			int col , diff;
			fo(0,x,n)
			{
				col = getcol(x);
				if(col!=-1)
				{
					diff = min(n-x,m-col)-1;
					if(diff+1>res)
					res = max(res,diagonal(x,col,x+diff,col+diff));
				}
			}
			printf("%d\n",res);
		}
		puts("-");
	}
}

