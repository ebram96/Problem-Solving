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
	int left[100001] , right[100001] , l , r , s , b;
	while(scanf("%d %d" , &s , &b))
	{
		if(!s)break;
		for(int i = 1 ; i <= s ; i++)
			left[i] = i-1 , right[i] = i+1;
		right[s] = 0;
		fo(y , b)
		{
			scanf("%d %d" , &l , &r);
			left[right[r]] = left[l];
			if(left[l])
				printf("%d " , left[l]);
			else printf("* ");
			right[left[l]] = right[r];
			if(right[r])
				printf("%d\n" , right[r]);
			else printf("*\n");
		}
		puts("-");
	}
}
