//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<cstdint>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<cstring>
#include<cmath>
#include<unordered_map>
#include<climits>
#include<set>
#include<unordered_set>
#define endl '\n'
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define lne if(line)puts("");else line = 1;
#define pb push_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define non if(!n)break;
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//inline bool bin(string a , string b){return a > b;}
//inline bool bin(int a , int b){return a > b;}
//inline bool bin(ull a , ull b){return a > b;}
char a[4][4] , orig[4][4];
int n , unx = -1 , uny = -1;
bool safe(int x , int y)
{
	for(int i = x ; i >= 0 && a[i][y]!='X' ; i--)if(a[i][y] == 'R')return 0;
	for(int i = x ; i <  n && a[i][y]!='X' ; i++)if(a[i][y] == 'R')return 0;
	for(int i = y ; i >= 0 && a[x][i]!='X' ; i--)if(a[x][i] == 'R')return 0;
	for(int i = y ; i <  n && a[x][i]!='X' ; i++)if(a[x][i] == 'R')return 0;
	return 1;
}
void reset(){fo(y , n)fo(i , n)a[y][i] = orig[y][i];}
int solve(int x , int y)
{
	if(y==n)y = 0 , x++;
	if(x==n)return 0;
	int ret = 0;
	if(unx != -1)return ret = max(ret , solve(x , y+1));
	if(a[x][y] != 'X' && safe(x , y))
	{
		a[x][y] = 'R';
		ret = max(ret , 1+solve(x , y+1));
		a[x][y] = '.';
	}
	return ret = max(ret , solve(x , y+1));
}
int main()
{
	//readf
	int res;
	while(scanf("%d" , &n))
	{
		non
		res &= 0;
		fo(x , n)fo(y , n)scanf(" %c" , &orig[x][y]) , a[x][y] = orig[x][y];
		fo(x , n)fo(y , n)
			if(a[x][y]!='X')
			{
				a[x][y] = 'R';
				res = max(res , 1+solve(0 , 0));
				reset();
				unx = x , uny = y;
				res = max(res , solve(0 , 0));
				unx = uny = -1;
			}
		printf("%d\n" , res);
	}

}
