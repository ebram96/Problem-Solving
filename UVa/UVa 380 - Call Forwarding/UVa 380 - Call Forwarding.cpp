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
struct Forward
{
	int x , d , dest;
};
vector<Forward> v[10000];
bool mars[10000];
int rec(int d ,int to)
{
	if(mars[to])return 9999;
	mars[to]=1;
	int sz = v[to].size() , ret=0;
	fo(0,y,sz)if(d>=v[to][y].x&&d<=v[to][y].x+v[to][y].d)
	{
		ret = v[to][y].dest;
		break;
	}
	return ret?rec(d,ret):to;
}
int main()
{
	//readf
	int t , c = 1 , i , d , to;
	scanf("%d",&t);
	Forward tmp;
	puts("CALL FORWARDING OUTPUT");
	wtm
	{
		printf("SYSTEM %d\n",c++);
		while(scanf("%d",&i)&&i)
			scanf("%d%d%d",&tmp.x,&tmp.d,&tmp.dest),v[i].pb(tmp);
		while(scanf("%d",&d)&&d!=9000)
		{
			memset(mars,0,sizeof(mars));
			scanf("%d",&to);
			printf("AT %.4d CALL TO %.4d RINGS %.4d\n",d,to,rec(d,to));
		}
		fo(0,y,10000)v[y].clear();
	}
	puts("END OF OUTPUT");
}
