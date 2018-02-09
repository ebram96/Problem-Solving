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
	string inp , res;
	ui n;
	while(scanf("%lld" , &n) && n)
	{
		res = "+x";
		n--;
		while(n--)
		{
			cin>>inp;
			if(inp!="No")
			{
				if(res=="+x")
				{
					res = inp;
				}
				else if(res=="-x")
				{
					if(inp=="-z")
						res = "+z";
					else if(inp == "+z")
						res = "-z";
					else if(inp == "-y")
						res = "+y";
					else if(inp == "+y")
						res = "-y";
				}
				else if(res=="+y")
				{
					if(inp == "-y")
						res = "+x";
					else if(inp == "+y")
						res = "-x";
				}
				else if(res=="-y")
				{
					if(inp == "-y")
						res = "-x";
					else if(inp == "+y")
						res = "+x";
				}
				else if(res=="+z")
				{
					if(inp == "-z")
						res = "+x";
					else if(inp == "+z")
						res = "-x";
				}
				else
				{
					if(inp == "-z")
						res = "-x";
					else if(inp == "+z")
						res = "+x";
				}
			}
		}
		printf("%s\n" , res.c_str());
	}
}

