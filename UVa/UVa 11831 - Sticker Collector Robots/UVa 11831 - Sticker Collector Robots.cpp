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
int n , m , s , init_x , init_y , prev_x , prev_y , res;
char inst[50001] , grid[100][100];
inline bool valid(int x,int y)
{return !(x<0||x==n||y<0||y==m);}
void dfs(int x,int y,char orien,int i)
{
	if(grid[x][y]=='#'||!valid(x,y))
	{
		dfs(prev_x,prev_y,orien,i);
		return;
	}
	if(grid[x][y]=='*')
	{
		res++;
		grid[x][y] = '.';
	}
	if(i==s)return ;
	prev_x = x , prev_y = y;
	if(orien=='N')
	{
		if(inst[i]=='D')dfs(x,y,'L',i+1);
		else if(inst[i]=='E')dfs(x,y,'O',i+1);
		else dfs(x-1,y,orien,i+1);
	}
	else if(orien=='S')
	{
		if(inst[i]=='D')dfs(x,y,'O',i+1);
		else if(inst[i]=='E')dfs(x,y,'L',i+1);
		else dfs(x+1,y,orien,i+1);
	}
	else if(orien=='L')
	{
		if(inst[i]=='D')dfs(x,y,'S',i+1);
		else if(inst[i]=='E')dfs(x,y,'N',i+1);
		else dfs(x,y+1,orien,i+1);
	}
	else
	{
		if(inst[i]=='D')dfs(x,y,'N',i+1);
		else if(inst[i]=='E')dfs(x,y,'S',i+1);
		else dfs(x,y-1,orien,i+1);
	}
}
int main()
{
	//readf
	while(scanf("%d %d %d",&n,&m,&s)&&n)
	{
		fo(0,x,n)fo(0,y,m)
		{
			scanf(" %c",&grid[x][y]);
			if(isalpha(grid[x][y]))
			{
				init_x = x;
				init_y = y;
			}
		}
		scanf("%s",inst);
		res = 0;
		dfs(init_x,init_y,grid[init_x][init_y],0);
		printf("%d\n",res);
	}
}

