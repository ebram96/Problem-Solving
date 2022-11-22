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
	unordered_map<long long , long long> m;
	long long a[1000000] , ind =0;
	while(scanf("%lld" , &a[ind]) == 1)
		m[a[ind++]]++;
	fo(y , ind)
		if(m[a[y]])
		printf("%lld %lld\n" , a[y] , m[a[y]]) , m[a[y]] = 0;
}
