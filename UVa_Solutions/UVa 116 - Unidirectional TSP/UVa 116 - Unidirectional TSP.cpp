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
int n , m , a[10][100] , mars[10][100] , source , res , ret;
ui dir[10][100];
int rec(int x , int y)
{
	if(x==n||y==m)return 0;
	if(x==n-1&&y==m-1)return a[x][y];
	int &ret = mars[x][y] , up , right , down , mn;
	if(~ret)return mars[x][y];
	up = a[x][y]+rec(x?x-1:n-1,y+1);
	right = a[x][y]+rec(x,y+1);
	down = a[x][y]+rec((x+1)%n,y+1);
	mn = min(up,min(right,down));
	if(mn==up)dir[x][y] = (x?x-1:n-1);
	if(mn==right)dir[x][y] = min(dir[x][y],ui(x));
	if(mn==down)dir[x][y] = min(dir[x][y],ui((x+1)%n));
	return ret = mn;
}
int main()
{
	//readf
	while(scanf("%d %d",&n,&m)==2)
	{
		memset(mars,-1,sizeof(mars));
		memset(dir,-1,sizeof(dir));
		res = INF;
		fo(0,x,n)fo(0,y,m)
			scanf("%d",&a[x][y]);
		fo(0,x,n)
		{
			ret = rec(x,0);
			if(ret<res)
			{
				res = ret;
				source = x;
			}
		}
		printf("%d",source+1);
		fo(0,y,m-1)
		{
			source = dir[source][y];
			printf(" %d",source+1);
		}
		printf("\n%d\n",res);
	}
}

