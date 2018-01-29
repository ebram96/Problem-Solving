//It's all about what U BELIEVE
#include<iostream>
#include<bits/stdc++.h>
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
#define fo(s,y,z) for(int y=s ; y<(int)z ; y++)
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
int n , q , a[10000] , c , *low , v;
int main()
{
	//readf
	while(scanf("%d %d",&n,&q)&&n)
	{
		fo(0,y,n)scanf("%d",&a[y]);
		sort(a,a+n);
		printf("CASE# %d:\n",++c);
		fo(0,y,q)
		{
			scanf("%d",&v);
			low = lower_bound(a,a+n,v);
			if(low==a+n||*low!=v)printf("%d not found\n",v);
			else printf("%d found at %d\n",v,int(low-a+1));
		}
	}
}

