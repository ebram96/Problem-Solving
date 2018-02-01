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
int n , m , nonz[1000] , c , ind;
struct Value
{int val , col;};
int main()
{
	// I know there is some optimization but I'm lazy :D
	//readf
	Value tmp;
	while(scanf("%d%d",&n,&m)==2)
	{
		vector<Value> v[10001];
		fo(1,y,n+1)
		{
			tmp.col = y;
			scanf("%d",&c);
			fo(0,i,c)scanf("%d",&nonz[i]);
			fo(0,i,c)
			{
				scanf("%d",&tmp.val);//M(y,nonz[i])
				v[nonz[i]].pb(tmp);  //M(nonz[i],y)
			}
		}
		printf("%d %d\n",m,n);
		int sz ;
		fo(1,y,m+1)
		{
			sz = v[y].size();
			if(!sz)
			{
				puts("0\n");
				continue;
			}
			printf("%d",sz);
			fo(0,i,sz)printf(" %d",v[y][i].col);
			printf("\n%d",v[y][0].val);
			fo(1,i,sz)printf(" %d",v[y][i].val);
			puts("");
		}
	}
}
