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
int c , r , p[50000] , sz[50000] , res , i , j;
map<string,int> mp;
char si[31] , sj[31];
int getp(int node)
{return p[node]=(p[node]==node?node:getp(p[node]));}
void unit(int a , int b)
{
	int x = getp(a) , y = getp(b);
	if(x==y)return ;
	if(sz[x]<sz[y])swap(x,y);
	p[y]=x;
	sz[x]+=sz[y];
	res=max(res,sz[x]);
}
int main()
{
	//readf
	while(scanf("%d%d",&c,&r)&&c)
	{
		res = 1;
		fo(0,y,c)
		{
			scanf("%s",si);
			mp[si]=y;
			p[y]=y;
			sz[y]=1;
		}
		fo(0,y,r)
		{
			scanf("%s%s",si,sj);
			i = mp[si] , j = mp[sj];
			unit(i,j);
		}
		printf("%d\n",res);
	}
}
