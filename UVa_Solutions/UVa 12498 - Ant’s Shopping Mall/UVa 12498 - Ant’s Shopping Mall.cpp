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
int n , m;
char board[50][50];
bool fail;
inline int get_closest_zero(int x,int y)
{
	bool found_zero = 0;
	int orig_y = y , ret = ~(1<<31);
	while(y<m)
	{
		if(board[x][y]=='0')
		{
			found_zero = 1;
			break;
		}
		y++;
	}
	if(found_zero)ret = y-orig_y;
	y = orig_y;
	found_zero = 0;
	while(y>=0)
	{
		if(board[x][y]=='0')
		{
			found_zero = 1;
			break;
		}
		y--;
	}
	if(found_zero)return min(ret,orig_y-y);
	return ret;
}
int main()
{
	//readf
	int t , cnt , c = 1 , res;
	scanf("%d",&t);
	wtm
	{
		scanf("%d %d",&n,&m);
		fail = 0;
		fo(0,x,n)
		{
			cnt = 0;
			fo(0,y,m)
			{
				scanf(" %c ",&board[x][y]);
				if(board[x][y]=='1')cnt++;
			}
			if(cnt==m)fail = 1;
		}
		if(fail)
		{
			printf("Case %d: -1\n",c++);
			continue;
		}
		res = ~(1<<31);
		fo(0,x,m)
		{
			cnt = 0;
			fo(0,y,n)
				cnt+=get_closest_zero(y,x);
			res = min(res,cnt);
		}
		printf("Case %d: %d\n",c++,res);
	}
}

