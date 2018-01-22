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
	int n , m , t;
	char c;
	t = getchar_unlocked() - '0';
	wtm
	{
		scanf("\n%c %d %d" , &c , &m , &n);
		if(m ==1)
		{
			if(n == 1)
			{
				puts("1");
				continue;
			}
		}
		if(c == 'K')
		{
			if(m%2)++m;
			if(n%2)++n;
			printf("%d\n" , m*n/4);
		}
		else if(c == 'k')
		{
			if(n == 1 || m == 1)
				printf("%d\n" , (m >= n ? m : n));
			else if(n == 2)
			{
				int res = 4*(m/4);
				if(m%4 == 1)res+=2;
				else if(m%4)res+=4;
				printf("%d\n" , res);
			}
			else if(m == 2)
			{
				int res = 4*(n/4);
				if(n%4 == 1)res+=2;
				else if(n%4)res+=4;
				printf("%d\n" , res);
			}
			else
			{
				int res = (m/2) * (n/2);
				if(m%2)m++;
				if(n%2)n++;
				res+=m/2 * n/2;
				printf("%d\n" , res);
			}
		}
		else
			printf("%d\n" , m <= n ? m : n);
	}
}
