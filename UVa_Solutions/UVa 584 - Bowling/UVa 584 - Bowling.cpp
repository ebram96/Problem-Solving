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
using namespace std;
inline ui get_s(char* s)
{
	ui ind = 0;
	char c;
	while(c = getchar_unlocked())
		if(c == '\n')return ind;
		else s[ind++] = c;
}
int main()
{
	char s[40];
	while(ui len = get_s(s))//try faster
	{
		if(s[0] == 'G')break;
		int res = 0;
		ui cnt = 0;
		bool roll = 0;
		for(ui y = 0 ; y < len ; y+=2)
			if(s[y] == 'X')
			{
				cnt++;
				res+=10;
				if(s[y+2] == 'X')res+=10;
				else res+=s[y+2]-'0';
				if(s[y+4] == 'X')res+=10;
				else if(s[y+4] == '/')res+=10-(s[y+2]-'0');
				else res+=s[y+4]-'0';
				if(cnt == 10)break;
			}
			else if(s[y] == '/')
			{
				cnt++;
				roll = 0;
				res+=10-(s[y-2]-'0');
				if(s[y+2] == 'X')res+=10;
				else res+=s[y+2]-'0';
				if(cnt == 10)break;
			}
			else
			{
				if(roll)
				{
					roll = 0;
					cnt++;
				}
				else roll = 1;
				res+=s[y]-'0';
			}
		printf("%d\n" , res);
	}
}
