//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<map>
#include<cmath>
#include<set>
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define ull unsigned long long
#define pb push_back
#define gcu getchar_unlocked
#define wtm while(t--)
#define frop freopen("/home/ebram96/Desktop/in" , "r" , stdin);	freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
int main()
{
	frop
	bool line = 0;
	int n , res , set = 1 , a[50] , b[50] , tot , target , get;
	while(scanf("%d" , &n) == 1)
	{
		if(!n)break;
		tot = res = 0;
		fo(y , n)scanf("%d" , &a[y]) , tot+=a[y];
		target = tot/n;
		sort(a , a+n);
		fo(y , n)b[y] = a[y] > target ? a[y]-target : 0;
		for(int beg = 0 , end = n-1 ; beg != end && beg < end;beg++)
			while(a[beg] != target)
			{
				if(!b[end]){end--; continue;}
				get = target - a[beg];
				if(get < b[end])
				{
					res+=get;
					b[end]-=get;
					break;
				}
				else if(get == b[end])
				{
					end--;
					res+=get;
					break;
				}
				else
				{
					res+=b[end];
					a[beg]+=b[end--];
				}
			}
		if(line)puts("");
		line = 1;
		printf("Set #%d\nThe minimum number of moves is %d.\n" , set++ , res);
	}
	puts("");
}
