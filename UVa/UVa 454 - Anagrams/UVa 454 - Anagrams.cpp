//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<unordered_map>
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define pb push_back
using namespace std;
int main()
{
	int n , t , len ;
	string s[100] , a[100];
	char inp[10001];
	scanf("%d\n\n" , &t);
	bool line = 0;
	while(t--)
	{
		n = 0;
		while(fgets(inp , 10000 , stdin))
		{
			if(inp[0] == '\n')break;
			inp[strlen(inp)-1] = '\0';
			s[n] = inp;
			n++;
		}
		sort(s , s+n);
		copy(s , s+n , a);
		fo(y , n)
		{
			len = a[y].length();
			fo(i , len)
				if(a[y][i] == ' ')
				{
					a[y].erase(i , 1);
					len--;
					i--;
				}
			//remove(a[y].begin() , a[y].end() , ' ');
			sort(a[y].begin() , a[y].end());
		}
		if(line)
			puts("");
		line = 1;
		fo(y , n-1)
			for(int i = y+1 ; i < n ; i++)
				if(a[y] == a[i])printf("%s = %s\n" , s[y].c_str() , s[i].c_str());

		scanf("\n");
	}
}
