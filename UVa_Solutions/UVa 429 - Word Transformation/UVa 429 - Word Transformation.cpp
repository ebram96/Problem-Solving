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
int t , n , dist[200] , len[200];
char word[200][11];
map<string,int>mp;
struct State
{
	int u , cost;
	inline bool operator<(const State &s)const
	{return s.cost<cost;}
};
inline int dijkstra(int source,int destination)
{
	fo(0,y,n)dist[y] = INF;
	priority_queue<State> pq;
	int u , cost , diff;
	pq.push({source,0});
	while(!pq.empty())
	{
		u = pq.top().u , cost = pq.top().cost;
		pq.pop();
		if(u==destination)return cost;
		if(dist[u]!=INF)
		{
			dist[u] = min(dist[u],cost);
			continue;
		}
		dist[u] = min(dist[u],cost);
		fo(0,y,n)if(len[y]==len[u]&&u!=y)
		{
			diff = 0;
			fo(0,i,len[y])
				diff+=(word[y][i]!=word[u][i]);
			if(diff==1)pq.push({y,cost+1});
		}
	}
}
int main()
{
	//readf
	//The better solution is to use BFS instead of Dijkstra's
	int u , v;
	char buff[22] , us[11] , vs[11] , line;
	scanf("%d",&t);
	wtm
	{
		mp.clear();
		n = 0;
		while(scanf("%s",word[n])&&word[n][0]!='*')
		{
			len[n] = strlen(word[n]);
			mp[word[n]] = n;
			n++;
		}
		getchar();
		while(scanf("%[^\n]",buff)==1&&buff[0]!='\n')
		{
			sscanf(buff,"%s %s",us,vs);
			u = mp[us] , v = mp[vs];
			printf("%s %s %d\n",us,vs,dijkstra(u,v));
			if(scanf("%c",&line)!=1)break;
		}
		if(t)puts("");
	}
}

