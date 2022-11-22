//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<cstdint>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<cstring>
#include<cmath>
#include<unordered_map>
#include<climits>
#include<set>
#include<unordered_set>
#define endl '\n'
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define lne if(line)puts("");else line = 1;
#define pb push_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define non if(!n)break;
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//inline bool bin(string a , string b){return a > b;}
//inline bool bin(int a , int b){return a > b;}
//inline bool bin(ull a , ull b){return a > b;}
int print_dash(int n)
{
	if(!n)return 0 ;
	putchar('-');
	return print_dash(n-1);
}
int print_up(int n)
{
	if(!n)return 0 ;
	putchar('|');
	return print_up(n-1);
}
int print_space(int n)
{
	if(!n)return 0 ;
	putchar(' ');
	return print_space(n-1);
}
int main()
{
	readf
	//writef
	int n;
	bool line = 0;
	char s[15];
	while(scanf("%d %s" , &n , s)==2)
	{
		non
		lne
		fo(y , strlen(s))
		{
			if(s[y] == '1')print_space(n+2);
			else if(s[y]=='4')print_space(n+2);
			else
			{
				putchar(' ');
				print_dash(n);
				putchar(' ');
			}
			if(y!=strlen(s)-1)putchar(' ');
		}
		puts("");
		//second part
		fo(i , n)
		{
			fo(y , strlen(s))
			{
				if(s[y] == '1')print_space(n+1) , putchar('|');
				else
				{
					putchar(s[y] == '2' || s[y] == '7'|| s[y] == '3' ? ' ':'|');
					print_space(n);
					putchar(s[y] == '5'||s[y]=='6'? ' ':'|');
				}
				if(y != strlen(s)-1)putchar(' ');
			}
			puts("");
		}
		//third part
		fo(y , strlen(s))
		{
			if(s[y] == '1')print_space(n+2);
			else if(s[y] == '0' || s[y] == '7')print_space(n+2);
			else
			{
				putchar(' ');
				print_dash(n);
				putchar(' ');
			}
			if(y!=strlen(s)-1)putchar(' ');
		}
		puts("");
		//4th part
		fo(i , n)
		{
			fo(y , strlen(s))
			{
				if(s[y] == '1')print_space(n+1) , putchar('|');
				else
				{
					putchar(s[y] == '2' || s[y] == '6'|| s[y] == '8' || s[y] == '0' ? '|':' ');
					print_space(n);
					putchar(s[y] != '2' ? '|':' ');
				}
				if(y != strlen(s)-1)putchar(' ');
			}
			puts("");
		}
		//last line
		fo(y , strlen(s))
		{
			if(s[y] == '1')print_space(n+2);
			else if(s[y]=='4'||s[y] == '7')print_space(n+2);
			else
			{
				putchar(' ');
				print_dash(n);
				putchar(' ');
			}
			if(y!=strlen(s)-1)putchar(' ');
		}
		puts("");
	}
	puts("");
}
