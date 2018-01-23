//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<map>
#include<cmath>
#include<set>
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui unsigned int
#define ull unsigned long long
#define pb push_back
#define gcu getchar_unlocked
#define wtm while(t--)
using namespace std;
int main()
{
	int n , start , end , div;
	while(scanf("%d" , &n))
	{
		if(!n)break;
		if(n==1)
		{
			puts("Printing order for 1 pages:\nSheet 1, front: Blank, 1");
			continue;
		}
		printf("Printing order for %d pages:\n" , n);
		start = n + (n%4?4-n%4:0);
		end = 1;
		div = n/4;
		if(n%4)div++;
		for(int i = 1 ; i <= div ; i++)
		{
			printf("Sheet %d, front: " , i);
			start>n?printf("Blank, %d\n" , end):printf("%d, %d\n" , start , end);
			start-- , end++;
			printf("Sheet %d, back : " , i);
			start>n?printf("%d, Blank\n" , end):printf("%d, %d\n" , end , start);
			start-- , end++;
		}
	}
}
