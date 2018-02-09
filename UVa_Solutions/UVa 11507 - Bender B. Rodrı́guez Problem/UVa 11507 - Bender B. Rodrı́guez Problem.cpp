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
	char inp[3] , res[3];
	unsigned int n;
	while(scanf("%u" , &n) && n)
	{
		res[0] = '+' , res[1] = 'x';
		n--;
		while(n--)
		{
			scanf("%s" , inp);
			if(inp[0] != 'N')
			{
				if(res[1] == 'x')
				{
					if(res[0] == '+')
					res[0] = inp[0] , res[1] = inp[1];
					else
					{
						if(inp[0] == '-')
						{
							if(inp[1] == 'z')
							res[0] = '+' , res[1] = 'z';
							else
							res[0] = '+' , res[1] = 'y';
						}
						else
						{
							if(inp[1] == 'z')
								res[0] = '-' , res[1] = 'z';
							else
								res[0] = '-' , res[1] = 'y';
						}
					}
				}
				else if(res[1] == 'y')
				{
					if(res[0] == '+')
					{
						if(inp[1] == 'y')
						{
							if(inp[0] == '-')
							res[0] = '+' , res[1] = 'x';
							else if(inp[0] == '+')
							res[0] = '-' , res[1] = 'x';
						}
					}
					else if(inp[1] == 'y')
					{
						if(inp[0] == '-')
						res[0] = '-' , res[1] = 'x';
						else if(inp[0] == '+')
						res[0] = '+' , res[1] = 'x';
					}
				}
				else
				{
					if(res[0] == '+')
					{
						if(inp[1] == 'z')
						{
							if(inp[0] == '-')
								res[0] = '+' , res[1] = 'x';
							else if(inp[0] == '+')
								res[0] = '-' , res[1] = 'x';
						}
					}
					else if(inp[1] == 'z')
					{
						if(inp[0] == '-')
							res[0] = '-' , res[1] = 'x';
						else if(inp[0] == '+')
							res[0] = '+' , res[1] = 'x';
					}
				}
			}
		}
		res[2] = '\0';
		puts(res);
	}
}

