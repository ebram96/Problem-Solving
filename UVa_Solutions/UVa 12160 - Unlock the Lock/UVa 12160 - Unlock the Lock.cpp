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
int l , u , r , dist[10000] , button[10] , c;
struct State
{int node , cost;};
int dijkstra()
{
	fo(0,y,10000)dist[y]=INF;
	dist[l] = 0;
	queue<State>pq;
	pq.push({l,0});
	int node , cost , new_node;
	while(!pq.empty())
	{
		node = pq.front().node , cost = pq.front().cost;
		if(node==u)return cost;
		pq.pop();
		fo(0,y,r)
		{
			new_node = (node+button[y])%10000;
			if(dist[new_node]>cost+1)
			{
				dist[new_node] = cost+1;
				pq.push({new_node,cost+1});
			}
		}
	}
	return -1;
}
int main()
{
	//readf
	int res;
	while(scanf("%d %d %d",&l,&u,&r)&&r)
	{
		fo(0,y,r)scanf("%d",&button[y]);
		res = dijkstra();
		if(~res)printf("Case %d: %d\n",++c,res);
		else printf("Case %d: Permanently Locked\n",++c);
	}
}

