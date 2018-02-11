// It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<cmath>
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui long long
//using namespace std;
int main()
{
	int x , y , a , b ;ui res ;
	while(scanf("%d" , &y)&&y)
	{

		scanf("%d\n%d" ,&x, &a);
		res = y - a;
		x--;
		b = a;
		while(x--)
		{
			scanf(" %d" , &a);
			(a < b ? res += b-a , b = a : b = a);
		}
		printf("%lld\n",res);
	}
}

