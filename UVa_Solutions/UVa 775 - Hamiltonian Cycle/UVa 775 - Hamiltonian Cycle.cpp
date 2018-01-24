//It's all about what U BELIEVE
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<stdio.h>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<cstring>
#include<cmath>
#include<set>
#define INF ~(1<<31)
#define endl '\n'
#define fo(s , y , z) for(int y = s ; y < (int)z ; y++)
#define pb push_back
#define pob pop_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define lne if(line)puts("");else line =1
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pairii ;
typedef pair<ull,ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
//int dx[]={-1,0,1, 0};
//int dy[]={ 0,1,0,-1};
int n , i , j , path[256] , root;
vi adj[257];
char bfr[8];
bool mars[257] , res;
void dfs(int node,int ind)
{
	if(node==root&&ind==n)
	{
		res = 1;
		return;
	}
	if(res||mars[node])return;
	mars[node] = 1;
	path[ind] = node;
	int sz = adj[node].size();
	fo(0,y,sz)
		dfs(adj[node][y],ind+1);
}
int main()
{
	//readf
	//writef
	while(scanf("%d ",&n)==1)
	{
		fo(1,y,n+1)adj[y].clear();
		while(scanf("%[^\n]\n",bfr))
		{
			if(bfr[0]=='%')break;
			sscanf(bfr,"%d %d",&i,&j);
			adj[i].pb(j);
			adj[j].pb(i);
		}
		int node = 1;
		res = 0;
		while(node<=n&&!res)
		{
			memset(mars,0,sizeof(mars));
			root = node++;
			dfs(root,0);
		}
		if(res)
		{
			printf("%d",root);
			fo(1,y,n)printf(" %d",path[y]);
			printf(" %d\n",root);
		}
		else puts("N");
	}
}

