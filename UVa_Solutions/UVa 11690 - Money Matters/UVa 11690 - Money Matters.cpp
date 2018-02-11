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
#define pob pop_back
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
int t , n , m , p[10000] , sum[10000] , i , j;
int getp(int node)
{return p[node]=(p[node]==node?node:getp(p[node]));}
void unit(int a , int b)
{
	int x = getp(a) , y = getp(b);
	if(x==y)return ;
	p[y]=x;
	sum[x]+=sum[y];
}
int main()
{
	//readf
	bool res;
	scanf("%d",&t);
	wtm
	{
		scanf("%d%d",&n,&m);
		fo(0,y,n)
		{
			scanf("%d",&sum[y]);
			p[y]=y;
		}
		fo(0,y,m)
		{
			scanf("%d %d",&i,&j);
			unit(i,j);
		}
		res = 1;
		fo(0,y,n)if(sum[getp(y)])
		{
			res = 0;
			break;
		}
		puts(res?"POSSIBLE":"IMPOSSIBLE");
	}
}
