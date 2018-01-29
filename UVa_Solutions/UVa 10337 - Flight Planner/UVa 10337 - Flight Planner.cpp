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
//int dx[]={-1,0,1, 0};
//int dy[]={ 0,1,0,-1};
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
int t , n , a[10][1000] , mars[10][1000];
inline bool valid(int &x,int &y)
{return y<=n&&x>=0&&x<=9;}
int rec(int x,int y)
{
	if(!valid(x,y))return 1e9;
	if(y==n)return !x?0:1e9;
	if(~mars[x][y])return mars[x][y];
	return mars[x][y] = min(60-a[x][y]+rec(x+1,y+1),
						min(30-a[x][y]+rec(x,y+1),
							20-a[x][y]+rec(x-1,y+1)));
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		scanf("%d",&n);
		n/=100;
		for(int x = 9;x>=0;x--)fo(0,y,n)
			scanf("%d",&a[x][y]);
		memset(mars,-1,sizeof(mars));
		printf("%d\n\n",rec(0,0));
	}
}

