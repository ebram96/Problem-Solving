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
char s[11] , ex[4] = {'A' , 'C' , 'G', 'T'};
set<string> res;
map<pair<string,int>,bool>mars;
int t , n , k;
void rec(int k)
{
	if(!k)
	{
		res.insert(s);
		return;
	}
	if(mars[{s,k}])return;
	mars[{s,k}]=1;
	char c;
	fo(0,y,n)
	{
		c = s[y];
		fo(0,x,4)
		{
			s[y] = ex[x];
			rec(k-1);
		}
		s[y] = c;
	}
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		scanf("%d%d%s",&n,&k,s);
		rec(k);
		printf("%lu\n",res.size());
		for(auto j : res)
			puts(j.c_str());
		res.clear();
		mars.clear();
	}
}

