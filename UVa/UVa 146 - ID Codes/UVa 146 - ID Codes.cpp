//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<map>
#include<unordered_map>
//#include<bitset>
//#include<tuple>
#include<cmath>
//#include<cstdint>
#include<climits>
#include<set>
//#include<unordered_set>
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define ull unsigned long long
#define pb push_back
#define gcu getchar_unlocked
#define wtm while(t--)
#define non if(!n)break;
#define frop freopen("/home/ebram96/Desktop/in" , "r" , stdin);	freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
bool bin(string a , string b){return a > b;}
bool bina(int a , int b){return a > b;}
bool bin(ull a , ull b){return a > b;}
int main()
{
	frop
	char s[50];
	while(scanf("%s" , s))
	{
		if(s[0]=='#')break;
		puts(next_permutation(s , s+strlen(s)) ? s : "No Successor");
	}
}
