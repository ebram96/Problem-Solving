//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<map>
/*#include"head.h"
#include <sys/types.h>
#include <sys/stat.h>*/
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define pb push_back
#define wtm while(t--)
using namespace std;
int main()
{
	ui n , m;
	while(scanf("%d %d" , &m , &n))
	{
		if(!m && !n)break;
		if(!m || !n)
			printf("0 knights may be placed on a %u row %u column board.\n" , m , n);
		else if(n == 1 || m == 1)
			printf("%u knights may be placed on a %u row %u column board.\n" , (m >= n ? m : n) , m , n);
		else if(n == 2)
		{
			int res = 4*(m/4);
			if(m%4 == 1)res+=2;
			else if(m%4)res+=4;
			printf("%u knights may be placed on a %u row %u column board.\n" , res , m , n);
		}
		else if(m == 2)
		{
			int res = 4*(n/4);
			if(n%4 == 1)res+=2;
			else if(n%4)res+=4;
			printf("%u knights may be placed on a %u row %u column board.\n" , res , m , n);
		}
		else
		{
			ui res = (m/2) * (n/2);
			ui a = m , b = n;
			if(m%2)m++;
			if(n%2)n++;
			res+=(m/2) * (n/2);
			printf("%u knights may be placed on a %u row %u column board.\n" , res , a , b);
		}
	}
}
