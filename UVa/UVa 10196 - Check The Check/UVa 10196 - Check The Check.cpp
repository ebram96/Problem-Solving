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
#define non if(!n)break;
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
int dx[]={1,-1, 0,0};
int dy[]={0, 0,-1,1};
int KX , KY , kx , ky;
char board[8][8];
char VHK[] = {'r','q'} , vhk[] = {'R','Q'};
char DK[] = {'b','q'} , dk[] = {'B','Q'};
inline bool valid(int x ,int y)
{return !(x<0||y<0||x==8||y==8);}
inline bool pawn(bool pl , int x , int y)
{
	if(pl)
	{
		if(valid(x-1,y-1)&&board[x-1][y-1]=='p')return 1;
		if(valid(x-1,y+1)&&board[x-1][y+1]=='p')return 1;
	}
	else
	{
		if(valid(x+1,y-1)&&board[x+1][y-1]=='P')return 1;
		if(valid(x+1,y+1)&&board[x+1][y+1]=='P')return 1;
	}
	return 0;
}
inline bool knight(bool pl , int x , int y)
{
	char c = (pl?'n':'N');
	int px[]={-1,-2,-2,-1,+1,+2,+2,+1};
	int py[]={-2,-1,+1,+2,+2,+1,-1,-2};
	fo(0,j,8)
		if(valid(x+px[j],y+py[j])&&board[x+px[j]][y+py[j]]==c)return 1;
	return 0;
}
inline bool horiz_vert(bool pl , int x , int y)
{
	char *vh = (pl?VHK:vhk);
	int ty = y , tx = x;
	y++;
	while(valid(x,y))
	{
		fo(0,j,2)if(board[x][y]==vh[j])return 1;
		if(board[x][y]!='.')break;
		y++;
	}
	y = ty , x++;
	while(valid(x,y))
	{
		fo(0,j,2)if(board[x][y]==vh[j])return 1;
		if(board[x][y]!='.')break;
		x++;
	}
	x = tx , y--;
	while(valid(x,y))
	{
		fo(0,j,2)if(board[x][y]==vh[j])return 1;
		if(board[x][y]!='.')break;
		y--;
	}
	y = ty , x--;
	while(valid(x,y))
	{
		fo(0,j,2)if(board[x][y]==vh[j])return 1;
		if(board[x][y]!='.')break;
		x--;
	}
	return 0;
}
inline bool diag(bool pl , int x , int y)
{
	char *d = (pl?DK:dk);
	int ty = y , tx = x;
	x++ , y++;
	while(valid(x,y))
	{
		fo(0,j,2)if(board[x][y]==d[j])return 1;
		if(board[x][y]!='.')break;
		y++ , x++;
	}
	x = tx+1 , y = ty-1;
	while(valid(x,y))
	{
		fo(0,j,2)if(board[x][y]==d[j])return 1;
		if(board[x][y]!='.')break;
		x++ , y--;
	}
	x = tx-1 , y = ty-1;
	while(valid(x,y))
	{
		fo(0,j,2)if(board[x][y]==d[j])return 1;
		if(board[x][y]!='.')break;
		y-- , x--;
	}
	x = tx-1 , y = ty+1;
	while(valid(x,y))
	{
		fo(0,j,2)if(board[x][y]==d[j])return 1;
		if(board[x][y]!='.')break;
		x-- , y++;
	}
	return 0;
}
int main()
{
	//readf
	int c = 1;
	while(scanf("%s" , board[0]))
	{
		fo(1,y,8)scanf("%s" , board[y]);
		kx = -1;
		fo(0,x,8)fo(0,y,8)
				if(board[x][y]=='K')KX = x , KY = y;
				else if(board[x][y]=='k')kx = x , ky = y;
		if(kx==-1)break;
		if(pawn(1,KX,KY)||knight(1,KX,KY)||horiz_vert(1,KX,KY)||diag(1,KX,KY))
			printf("Game #%d: white king is in check.\n" , c++);
		else if(pawn(0,kx,ky)||knight(0,kx,ky)||horiz_vert(0,kx,ky)||diag(0,kx,ky))
			printf("Game #%d: black king is in check.\n" , c++);
		else printf("Game #%d: no king is in check.\n" , c++);
	}
}

