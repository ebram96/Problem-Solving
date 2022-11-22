//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
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
int n , m , res;
bool v[25][25];
void dfs(int node,int level)
{
	fo(0,y,n)if(v[node][y])
	{
		v[y][node]=v[node][y]=0;
		dfs(y,level+1);
		v[y][node]=v[node][y]=1;
	}
	res = max(res,level);
}
int main()
{
	//readf
	int i , j;
	while(scanf("%d%d",&n,&m)&&n)
	{
		memset(v,0,sizeof(v));
		while(m--)
		{
			scanf("%d%d",&i,&j);
			v[i][j]=v[j][i]=1;
		}
		res = 0;
		fo(0,y,n)dfs(y,0);
		printf("%d\n",res);
	}
}
