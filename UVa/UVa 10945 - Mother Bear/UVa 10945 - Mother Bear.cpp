//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<cmath>
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define pb push_back
using namespace std;
bool pal(string s)
{
	ui len = s.length();
	fo(y , len)if(s[y] != s[len - y - 1])return 0;
	return 1;
}
int main ()
{
	char s[20000];
	while(scanf("%[^\n]" , s))
	{
		if(!strcmp("DONE" , s))break;
		scanf("\n");
		string str = s;
		ui len = strlen(s);
		fo(y , len)
		{
			if(!isalpha(str[y]))
			{
				str.erase(y , 1);
				y--;
				len--;
				continue;
			}
			if(str[y] > 'Z')str[y]-=32;
		}
		if(pal(str))puts("You won't be eaten!");
		else puts("Uh oh..");
	}
}
