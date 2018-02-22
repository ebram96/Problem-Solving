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
int t , n , res , c;
bool mars[100][100];
char grid[100][100];
bool ff(int x,int y)
{
	if(!(x>=0&&y>=0&&x<n&&y<n)||grid[x][y]=='.'||mars[x][y])return 0;
	mars[x][y] = 1;
	bool ret = (grid[x][y]=='x');
	fo(0,i,4)ret|=ff(x+dx[i],y+dy[i]);
	return ret;
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		scanf("%d",&n);
		fo(0,y,n)scanf("%s",grid[y]);
		memset(mars,0,sizeof(mars));
		res = 0;
		fo(0,x,n)fo(0,y,n)if(grid[x][y]!='.')
			res+=ff(x,y);
		printf("Case %d: %d\n",++c,res);
	}
}

