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
vi v[1000];
int main()
{
	//readf
	int n , p , tmp , mn , sz , res;
	char c;
	bool recur;
	scanf("%d",&n);
	wnm
	{
		scanf("%d ",&p);
		fo(0,y,p)v[y].clear();
		fo(0,y,p)
		{
			while(scanf("%d%c",&tmp,&c)==2&&c==' ')
				v[y].pb(tmp);
			v[y].pb(tmp);
		}
		recur = 0;
		mn = ~(1<<31);
		fo(0,y,p)
		{
			sz = v[y].size();
			if(sz<mn)
			{
				recur = 0;
				mn = sz;
				res = y+1;
			}
			else if(sz==mn)recur = 1;
		}
		printf("%d",res);
		if(recur)fo(res,y,p)
		{
			sz = v[y].size();
			if(sz==mn)printf(" %d",y+1);
		}
		puts("");
	}
}
