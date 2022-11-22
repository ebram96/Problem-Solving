// It's all about what U BELIEVE
#include<stdio.h>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cstring>
#include<iostream>
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui int
#define pb push_back
#define llu unsigned long long
#define lld long long
using namespace std;
int main()
{
	char a[1000][21] , com[21] , t[21] , b[1000][21];
	int n , c , test;
	bool line = 0;
	scanf("%d" , &test);
	while(test--)
	{
		scanf("%d" , &n);
		fo(y , n){scanf("%s" , a[y]);strcpy(b[y] , a[y]);sort(a[y] , a[y]+strlen(a[y]));}
		if(line)puts("");
		line = 1;
		while(scanf("%s" , com))
		{
			if(com[0]=='E')break;
			c = 1;
			strcpy(t , com);
			sort(com , com+strlen(com));
			printf("Anagrams for: %s\n" , t);
			for(int y = 0 ; y < n ; y++)
				if(!strcmp(com , a[y]))printf("%3d) %s\n" , c++ , b[y]);
			if(c==1)printf("No anagrams for: %s\n" , t);
		}
	}
}
