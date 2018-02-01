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
int main()
{
	//readf
	int C , t , n , r , c , dr , dc;
	scanf("%d" , &C);
	while(C--)
	{
		scanf("%d %d" , &t , &n);
		wtm
		{
			scanf("%d %d %d %d" , &r , &c , &dr , &dc);
			if((r+c)%2!=(dr+dc)%2)
				puts("no move");
			else if(r==dr&&c==dc)
				puts("0");
			else if(abs(r-dr) == abs(c-dc))
				puts("1");
			else puts("2");
		}
	}
}

