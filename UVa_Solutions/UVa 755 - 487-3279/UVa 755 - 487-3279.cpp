//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<map>
#include<cmath>
#include<set>
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define ull unsigned long long
#define pb push_back
#define gcu getchar_unlocked
#define wtm while(t--)
#define frop freopen("/home/ebram96/Desktop/in" , "r" , stdin);	freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
bool bin_s(string a , string b){return a > b;}
int main()
{
	frop
	bool line = 0;
	int t , n;
	char str[100];
	string s[100000];
	scanf("%d" , &t);
	wtm
	{
		scanf("%d" , &n);
		fo(y , n)scanf("%s" , str) , s[y] = str;
		fo(y , n)
		{
			ui len = s[y].length();
			string rep = "";
			fo(i , len)
			{
				if(s[y][i] <= 'C' && s[y][i] >= 'A')rep+='0'+2;
				else if(s[y][i] <= 'F' && s[y][i] >= 'D')rep+='0'+3;
				else if(s[y][i] <= 'I' && s[y][i] >= 'G')rep+='0'+4;
				else if(s[y][i] <= 'L' && s[y][i] >= 'J')rep+='0'+5;
				else if(s[y][i] <= 'O' && s[y][i] >= 'M')rep+='0'+6;
				else if(s[y][i] <= 'S' && s[y][i] >= 'P')rep+='0'+7;
				else if(s[y][i] <= 'V' && s[y][i] >= 'T')rep+='0'+8;
				else if(s[y][i] <= 'Y' && s[y][i] >= 'W')rep+='0'+9;
				else if(s[y][i] != '-')rep+=s[y][i];
			}
			s[y] = rep;
		}
		sort(s , s+n);
		int cnt_rep = 0;
		if(line)puts("");
		line = 1;
		bool done = 0;
		for(int y = 1 ; y < n ; y++)
		{
			if(s[y] == s[y-1])
				cnt_rep++;
			else if(cnt_rep)
			{
				s[y-1].insert(3 , 1 , '-');
				printf("%s %d\n" , s[y-1].c_str() , cnt_rep+1);
				cnt_rep = 0;
				done = 1;
			}
		}
		if(cnt_rep)
		{
			s[n-1].insert(3 , 1 , '-');
			printf("%s %d\n" , s[n-1].c_str() , cnt_rep+1);
			done = 1;
		}
		if(!done)puts("No duplicates.");
	}
}
