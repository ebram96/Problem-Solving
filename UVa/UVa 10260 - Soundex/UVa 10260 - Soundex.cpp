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
	freopen("/home/ebram96/Desktop/in" , "r" , stdin);
	freopen("/home/ebram96/Desktop/out" , "w" , stdout);
	char s[21];
	string res;
	int pre;
	while(scanf("%s" , s) == 1)
	{
		res = "";
		pre = 0;
		fo(y , strlen(s))
		{
			if(s[y] == 'B' || s[y] == 'F' || s[y] == 'P' || s[y] == 'V')
			{
				if(pre != 1)
				{
					res += '1';
					pre = 1;
				}
			}
			else if(s[y] == 'C' || s[y] == 'G' || s[y] == 'J' || s[y] == 'K' || s[y] == 'Q' || s[y] == 'S' || s[y] == 'X' || s[y] == 'Z')
			{
				if(pre != 2)
				{
					res += '2';
					pre = 2;
				}
			}
			else if(s[y] == 'D' || s[y] == 'T')
			{
				if(pre != 3)
				{
					res += '3';
					pre = 3;
				}
			}
			else if(s[y] == 'L')
			{
				if(pre != 4)
				{
					res += '4';
					pre = 4;
				}
			}
			else if(s[y] == 'M' || s[y] == 'N')
			{
				if(pre != 5)
				{
					res += '5';
					pre = 5;
				}
			}
			else if(s[y] == 'R')
			{
				if(pre != 6)
				{
					res += '6';
					pre = 6;
				}
			}
			else pre = 0;
		}
		puts(res.c_str());
	}
}
