//It's all about what U BELIEVE
#include<unistd.h>
#include<iostream>
#include<vector>
#include<cstdint>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<cstring>
#include<cmath>
#include<unordered_map>
#include<climits>
#include<set>
#include<unordered_set>
#define endl '\n'
#define fo(s , y , z) for(int y = s ; y < z ; y++)
#define lne if(line)puts("");else line = 1;
#define pb push_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define non if(!n)break;
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
int n , q , tree[400000] , s[100001] , e[100001];
int rmq(int node , int l , int r , int st , int en)
{
	if(l>en||r<st)return 0;
	if(st>=l&&en<=r)return tree[node];
	return max(rmq((node<<1) , l , r , st , (st+en)/2) ,rmq((node<<1)+1 , l , r , (st+en)/2+1 , en));
}
int build(int i , int st , int en , int node)
{
	if(st==en)return tree[node] = (e[i]-s[i]+1);
	if(i<=(st+en)/2)return tree[node] = max(tree[node] , build(i,st,(st+en)/2,(node<<1)));
	else return tree[node] = max(tree[node] , build(i,(st+en)/2+1,en,(node<<1)+1));
}
int main()
{
	readf
	int in , pre , l , r;
	while(scanf("%d" , &n)&&n)
	{
		scanf("%d" , &q);
		memset(tree , 0 , sizeof tree);
		scanf("%d" , &pre);
		l = r = 1;
		for(int y = 2 ; y <= n ; y++)
		{
			scanf("%d" , &in);
			if(pre!=in)
			{
				for(int i = l ; i <= r ; i++)
					s[i] = l , e[i] = r;
				pre = in;
				l = ++r;
			}
			else r++;
		}
		for(int i = l ; i <= r ; i++)
			s[i] = l , e[i] = r;
		fo(0 , y , n)build(y+1 , 1 , n , 1);
		int l_adj , r_adj;
		fo(0 , y , q)
		{
			scanf("%d %d" , &l , &r);
			if(l==s[l])l_adj = 0;
			else
			{
				if(r<=e[l])
				{
					printf("%d\n" , (r-l+1));
					continue;
				}
				else
				{
					l_adj = (e[l]-l+1);
					l = e[l]+1;
				}
			}
			if(r==e[r])r_adj = 0;
			else
			{
				if(l>=s[r])
				{
					printf("%d\n" , max(l_adj , (r-l+1)));
					continue;
				}
				else
				{
					r_adj = (r-s[r]+1);
					r = s[r]-1;
				}
			}
			printf("%d\n" , max(l_adj , max(r_adj , rmq(1 , l , r , 1 , n))));
		}
	}
}
