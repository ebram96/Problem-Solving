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
int n , ca , cb;
bool res , mars[1001][1001];
dqint dq;
bool cheerup(int a , int b)
{
	if(mars[a][b])return 0;
	mars[a][b]=1;
	if(a==n||b==n||res)return res = 1;
	if(a!=ca)
	{
		dq.pb(0);
		if(cheerup(ca,b))return 1;
		dq.pob();
	}
	if(b!=cb)
	{
		dq.pb(1);
		if(cheerup(a,cb))return 1;
		dq.pob();
	}
	if(a)
	{
		dq.pb(2);
		if(cheerup(0,b))return 1;
		dq.pob();
		if(b!=cb)
		{
			int sub = (a>=cb-b?cb-b:a);
			dq.pb(4);
			if(cheerup(a-sub,b+sub))return 1;
			dq.pob();
		}
	}
	if(b)
	{
		dq.pb(3);
		if(cheerup(a,0))return 1;
		dq.pob();
		if(a!=ca)
		{
			int sub = (b>=ca-a?cb-a:b);
			dq.pb(5);
			if(cheerup(a+sub,b-sub))return 1;
			dq.pob();
		}
	}
	return 0;
}
int main()
{
	//readf
	char str[6][9]={"fill A" , "fill B" ,
					"empty A", "empty B",
					"pour A B","pour B A"};
	while(scanf("%d %d %d",&ca,&cb,&n)==3)
	{
		memset(mars,0,sizeof(mars));
		res = 0;
		dq.clear();
		cheerup(0,0);
		int sz = dq.size();
		fo(0,y,sz)puts(str[dq[y]]);
		puts("success");
	}
}
