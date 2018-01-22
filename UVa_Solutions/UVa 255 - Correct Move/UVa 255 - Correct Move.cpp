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
int dx[]={1,-1,0 ,0};
int dy[]={0, 0,-1,1};
inline bool valid(int x , int y)
{return !(x<0||y<0||x==8||y==8);}
int main()
{
	//readf
	int k , q , mv , y , x;
	bool board[8][8] , locked;
	while(scanf("%d %d %d" , &k , &q , &mv)==3)
	{
		memset(board , 0 , sizeof(board));
		if(k==q)
		{
			puts("Illegal state");
			continue;
		}
		if(!((mv!=k)&&(mv!=q)&&(((mv%8)==(q%8))||((mv/8)==(q/8)))))
		{
			puts("Illegal move");
			continue;
		}
		if(((mv/8==k/8)&&(k/8==q/8))&&((mv>k&&k>q)||(mv<k&&k<q)))
		{
			puts("Illegal move");
			continue;
		}
		if(((mv%8==k%8)&&(k%8==q%8))&&((mv<k&&k<q)||(mv>k&&k>q)))
		{
			puts("Illegal move");
			continue;
		}
		y = k/8 , x = k%8;
		fo(0,j,4)
			if(valid(y+dy[j],x+dx[j]))board[y+dy[j]][x+dx[j]]=1;
		y = mv/8 , x = mv%8;
		if(board[y][x])
		{
			puts("Move not allowed");
			continue;
		}
		y = k/8 , x = k%8;
		fo(0,j,4)
			if(valid(y+dy[j],x+dx[j]))board[y+dy[j]][x+dx[j]]=0;
		y = mv/8 , x = mv%8;
		for(int i = y ; i < 8 ; i++)board[y][i] = 1;
		for(int i = y ; i >=0 ; i--)board[y][i] = 1;
		for(int i = x ; i < 8 ; i++)board[i][x] = 1;
		for(int i = x ; i >=0 ; i--)board[i][x] = 1;
		y = k/8 , x = k%8;
		locked = 1;
		fo(0,j,4)
			if(valid(y+dy[j],x+dx[j])&&(!board[y+dy[j]][x+dx[j]]))locked = 0;
		puts(locked?"Stop":"Continue");
	}
}

