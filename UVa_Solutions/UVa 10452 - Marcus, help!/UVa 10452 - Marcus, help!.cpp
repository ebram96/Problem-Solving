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
char board[8][8];
int n , m , path[7] , ind;
bool valid(int x,int y)
{ return !(x<0||y<0||y==m); }
bool god(char& c)
{ return (c=='#'&&ind==6)||(c=='I')||(c=='E')||(c=='H')||(c=='O')||(c=='V')||(c=='A'); }
void traverse(int x , int y)
{
	if(board[x][y]=='#')return;
	board[x][y]='X';
	if(valid(x-1,y)&&god(board[x-1][y]))//forth
	{
		path[ind++]=0;
		traverse(x-1,y);
	}
	if(valid(x,y-1)&&god(board[x][y-1]))//left
	{
		path[ind++]=1;
		traverse(x,y-1);
	}
	if(valid(x,y+1)&&god(board[x][y+1]))//right
	{
		path[ind++]=2;
		traverse(x,y+1);
	}
}
int main()
{
	//readf
	int init_x , init_y , t;
	scanf("%d",&t);
	wtm
	{
		scanf("%d%d",&n,&m);
		fo(0,x,n)
		{
			scanf("%s",board[x]);
			fo(0,y,m)if(board[x][y]=='@')
			{
				init_x = x;
				init_y = y;
				break;
			}
		}
		ind = 0;
		traverse(init_x,init_y);
		// 0 forth
		// 1 left
		// 2 right
		printf("%s",path[0]==1?"left":(path[0]?"right":"forth"));
		fo(1,y,7)printf(" %s",path[y]==1?"left":(path[y]?"right":"forth"));
		puts("");
	}
}
