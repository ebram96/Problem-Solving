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
#include<unordered_set>
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
	bool line = 0;
	ui n , cnt;
	scanf("%u" , &n);
	gcu();
	gcu();
	char tree[31];
	while(n--)
	{
		map<string , float> m;
		cnt = 0;
		while(scanf("%[^\n]" , tree))
		{
			if(!strlen(tree))break;
			m[tree]++;
			cnt++;
			gcu();
			tree[0] = 0;
		}
		gcu();
		map<string , float>::iterator b = m.begin() , e = m.end();
		if(line)puts("");
		line = 1;
		while(b != e)
			printf("%s %.4f\n" , b->first.c_str() , b->second/cnt*100.0f) , ++b;
	}

}
