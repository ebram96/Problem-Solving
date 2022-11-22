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
int main()
{
	//readf
	int n , m , t , e , u , v , inp;
	ui sz;
	vi inc[28];
	bool res , adj[8][28];
	scanf("%d",&t);
	wtm
	{
		e = 0;
		res = 1;
		memset(adj,0,sizeof(adj));
		scanf("%d %d",&n,&m);
		fo(0,y,m)inc[y].clear();
		fo(0,x,n)fo(0,y,m)
		{
			scanf("%d",&inp);
			if(inp)inc[y].pb(x);
		}
		fo(0,y,m)
		{
			sz = inc[y].size();
			if(!sz)continue;
			if(sz%2)
			{
				res = 0;
				break;
			}
			fo(0,i,sz)
			{
				u = inc[y][i] , v = inc[y][i+1];
				i++;
				if(adj[u][v])
				{
					res = 0;
					break;
				}
				adj[u][v]=adj[v][u]=1;
				e++;
			}
		}
		puts(res&&e==m?"Yes":"No");
	}
}
