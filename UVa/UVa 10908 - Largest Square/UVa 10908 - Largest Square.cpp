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
int t , n , m , q , r , c ,up_x,up_y,down_x,down_y;
char board[100][100];
inline bool valid(int x , int y)
{return (x>=0&&x<n&&y>=0&&y<m);}
inline bool chk_right(int x , int y , int len)
{
	int cnt = 0 , orig_y = y;
	while(cnt<len&&valid(x,y)&&board[x][y]==board[r][c])
	{
		cnt++;
		y--;
	}
	if(cnt!=len)return 0;
	cnt = 0;
	y = orig_y;
	while(cnt<len&&valid(x,y)&&board[x][y]==board[r][c])
	{
		cnt++;
		x--;
	}
	return cnt==len;
}
inline bool chk_left(int x , int y , int len)
{
	int cnt = 0 , orig_y = y;
	while(cnt<len&&valid(x,y)&&board[x][y]==board[r][c])
	{
		cnt++;
		y++;
	}
	if(cnt!=len)return 0;
	cnt = 0;
	y = orig_y;
	while(cnt<len&&valid(x,y)&&board[x][y]==board[r][c])
	{
		cnt++;
		x++;
	}
	return cnt==len;
}
int main()
{
	//readf
	scanf("%d",&t);
	int side;
	wtm
	{
		scanf("%d %d %d",&n,&m,&q);
		fo(0,y,n)scanf("%s",board[y]);
		printf("%d %d %d\n",n,m,q);
		while(q--)
		{
			side = 1;
			scanf("%d %d",&r,&c);
			up_x = down_x = r;
			up_y = down_y = c;
			while(valid(up_x,up_y)&&valid(down_x,down_y))
			{
				if(!(chk_left(up_x,up_y,side)&&chk_right(down_x,down_y,side)))
					break;
				up_x-- , up_y--;
				down_x++ , down_y++;
				side+=2;
			}
			printf("%d\n",side-2);
		}
	}
}

