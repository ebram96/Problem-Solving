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
#define ui int
#define pb push_back
#define llu unsigned long long
#define lld long long
using namespace std;
//bool bin(llu a , llu b){return a > b;}
inline bool alpha(char& c)
{
	if(c=='.')c = '0';
	return (c != '*');
}
int main()
{
	bool line = 1;
	int n , m , c = 1;
	while(scanf("%d %d\n" , &n , &m))
	{
		if(!n)if(!m)break;
		char s[100][101];
		fo(y , n)scanf("%s" , s[y]);
		if(!line)
		{
			printf("\n");
			line = 0;
		}
		fo(y , n)
		{
			fo(i , m)
			{
				if(s[y][i]=='*')
				{
					if(y)if(alpha(s[y-1][i]))s[y-1][i]++;
					if(y&&i)if(alpha(s[y-1][i-1]))s[y-1][i-1]++;
					if(y&&i!=m-1)if(alpha(s[y-1][i+1]))s[y-1][i+1]++;
					if(i!=m-1){if(alpha(s[y][i+1]))s[y][i+1]++;}
					if(i){if(alpha(s[y][i-1]))s[y][i-1]++;}
					if(y!=n-1)
					{
						if(alpha(s[y+1][i]))s[y+1][i]++;
						if(i!=m-1)if(alpha(s[y+1][i+1]))s[y+1][i+1]++;
						if(i)if(alpha(s[y+1][i-1]))s[y+1][i-1]++;
					}
				}
				else if(s[y][i] == '.')s[y][i] = '0';
			}
		}
		printf("Field #%d:\n" , c++);
		fo(y , n)printf("%s\n" , s[y]);
		//printf("\n");
		line = 0;
	}
}
