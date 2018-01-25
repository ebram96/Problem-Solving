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
using namespace std;
int main()
{
	unsigned int n , t;
	scanf("%u" , &t);
	while(t--)
	{
		scanf("\n%u" , &n);
		unsigned int  res[10] = {0};
		for(unsigned int y = 1 ; y <= n ; y++)
		{
			unsigned int z = y;
			while(z)
			{
				res[z%10]++;
				z/=10;
			}
		}
		printf("%u" , res[0]);
		for(unsigned int y = 1 ; y < 10 ;y++)
			printf(" %u" , res[y]);
		printf("\n");
	}
}
