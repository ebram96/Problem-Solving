//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<map>
#include<unordered_map>
#include<bitset>
//#include<tuple>
#include<cmath>
//#include<cstdint>
#include<climits>
#include<set>
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
bool bin(int a , int b){return a > b;}
bool bin(ull a , ull b){return a > b;}
int main()
{
	frop
	char inp0[11] , inp1[11] , c;
	map<string , string> m;
	while(scanf("%s%c%s" , inp0 , &c , inp1) == 3)
	{
		if(c == '\n')
			break;
		m[inp1] = inp0;
	}
	puts(!m[inp0].size() ? "eh" : m[inp0].c_str());
	puts(!m[inp1].size() ? "eh" : m[inp1].c_str());
	while(scanf("%s" , inp0) == 1)
		puts(!m[inp0].size() ? "eh" : m[inp0].c_str());
}
