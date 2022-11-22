//It's all about what U BELIEVE
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<bitset>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#define endl '\n'
#define PI acos(-1)
#define INF ~(1<<31)
#define pb push_back
#define pob pop_back
#define wtm while(t--)
#define wnm while(n--)
#define lsone(Z) (Z&-Z)
#define modulo 1000000007
#define gcu getchar_unlocked
#define allof(Z) Z.begin(),Z.end()
#define rallof(Z) Z.rbegin(),Z.rend()
#define mset(z,v) memset(z,v,sizeof(z))
#define lne if(line)puts("");else line =1
#define fo(s,y,z) for(int y=s ; y<(int)z ; y++)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,ull> pairull;
typedef pair<int,int> pairii;
typedef vector<string> vstr;
typedef deque<int> dqint;
typedef set<ull> setull;
typedef unsigned int ui;
typedef queue<int> qint;
typedef vector<int> vi;
typedef set<int> seti;
typedef long long ll;
//int dx[]={-1,0,1, 0,-1,1, 1,-1};
//int dy[]={ 0,1,0,-1, 1,1,-1,-1};
int main()
{
	//readf
	int u , v , n = 0 , dist[101][101] , c = 1;
	double res;
	map<int , int>mp;
	while(scanf("%d %d",&u,&v)&&u)
	{
		n = 0;
		mp.clear();
		if(!mp[u])mp[u] = ++n;
		if(!mp[v])mp[v] = ++n;
		u = mp[u] , v = mp[v];
		fo(1,i,101)fo(1,j,101)
			dist[i][j] = 1e8;
		dist[u][v] = 1;
		while(scanf("%d %d",&u,&v)&&u)
		{
			if(!mp[u])mp[u] = ++n;
			if(!mp[v])mp[v] = ++n;
			u = mp[u] , v = mp[v];
			dist[u][v] = 1;
		}
		fo(1,k,n+1)fo(1,i,n+1)fo(1,j,n+1)
			dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
		res = 0;
		fo(1,i,n+1)fo(1,j,n+1)if(i!=j)
			res+=dist[i][j];
		printf("Case %d: average length between pages = %.3lf clicks\n",c++,res/(n*(n-1)));
	}
}

