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
int dx[]={-1,0,1, 0};
int dy[]={ 0,1,0,-1};
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
int m , n , init_x , init_y , res;
char grid[20][20] , c;
bool mars[20][20];
bool valid(int &x,int &y)
{return x>=0&&y>=0&&x<m&&y<n;}
int ff(int x,int y)
{
	if(!valid(x,y)||grid[x][y]!=c||mars[x][y])return 0;
	mars[x][y] = 1;
	int ret = (x==init_x&&y==init_y?-1e6:1) , new_x , new_y;
	fo(0,i,4)
	{
		new_x = x+dx[i] , new_y = y+dy[i];
		if(new_y<0)new_y = n-1;
		new_y%=n;
		ret+=ff(new_x,new_y);
	}
	return ret;
}
int main()
{
	//readf
	while(scanf("%d %d",&m,&n)==2)
	{
		fo(0,y,m)scanf("%s",grid[y]);
		scanf("%d %d",&init_x,&init_y);
		c = grid[init_x][init_y];
		memset(mars,0,sizeof(mars));
		res = 0;
		fo(0,x,m)fo(0,y,n)if(grid[x][y]==c)
			res = max(res,ff(x,y));
		printf("%d\n",res);
	}
}

