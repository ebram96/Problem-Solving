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
int corner , midline , diagonal , table , t , n , l , c = 1 , res;
int ball[75] , ticket[1000][5][5];
bool used_ball[75];
inline bool found(int v,int ball_bound)
{
	ball_bound = min(n,ball_bound);
	fo(0,y,ball_bound)if(v==ball[y]&&!used_ball[y])
		return used_ball[y] = 1;
	return 0;
}
inline int won_corner(int &i)
{
	memset(used_ball,0,sizeof(used_ball));
	if(!found(ticket[i][0][0],35))return 0;
	if(!found(ticket[i][0][4],35))return 0;
	if(!found(ticket[i][4][0],35))return 0;
	if(!found(ticket[i][4][4],35))return 0;
	return corner;
}
inline int won_midline(int &i)
{
	memset(used_ball,0,sizeof(used_ball));
	fo(0,y,5)if(!found(ticket[i][2][y],40))
		return 0;
	return midline;
}
inline int won_diagonal(int &i)
{
	memset(used_ball,0,sizeof(used_ball));
	for(int x = 0 , y = 0 ; x < 5 ; x++ , y++)
	{
		if(!found(ticket[i][x][y],45))return 0;
		if((x!=2)&&!found(ticket[i][4-x][y],45))return 0;
	}
	return diagonal;
}
inline int won_table(int &i)
{
	memset(used_ball,0,sizeof(used_ball));
	fo(0,x,5)fo(0,y,5)if(!found(ticket[i][x][y],n))
		return 0;
	return table;
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		scanf("%d %d",&n,&l);
		fo(0,y,n)scanf("%d",&ball[y]);
		scanf("%d %d %d %d",&corner , &midline , &diagonal , &table);
		fo(0,y,l)fo(0,i,5)fo(0,j,5)
			scanf("%d",&ticket[y][i][j]);
		printf("Case %d:\n",c++);
		fo(0,y,l)
		{
			res = 0;
			res+=won_corner(y);
			res+=won_diagonal(y);
			res+=won_midline(y);
			res+=won_table(y);
			printf("%d\n",res);
		}
		if(t)puts("");
	}
}

