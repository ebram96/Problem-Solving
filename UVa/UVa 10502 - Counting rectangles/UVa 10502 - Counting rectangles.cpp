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
int n , m;
bool a[100][100];
char inp;
inline bool valid(int &x,int &y)
{return (x<n&&y<m);}
inline bool horizontal_rect(int x,int c,int sz)
{
	for(int i=0,y=c;i<sz;i++,y++)
		if(!(valid(x,y)&&a[x][y]))
			return 0;
	return 1;
}
int main()
{
	//readf
	while(scanf("%d %d",&n,&m)==2)
	{
		int res = 0 , mx = max(n,m);
		fo(0,x,n)fo(0,y,m)
		{
			scanf(" %c ",&inp);
			a[x][y]=(inp=='1');
		}
		fo(1,sz,mx+1)
			fo(0,x,n)fo(0,y,m)
				if(horizontal_rect(x,y,sz))
				{
					res++;
					int r = x+1;
					while(horizontal_rect(r,y,sz))
						r++ , res++;
				}
		printf("%d\n",res);
	}
}

