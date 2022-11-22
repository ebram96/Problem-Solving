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
int main()
{
	unsigned long n ;
	char s[11];
	scanf("%lu" , &n);
	while(n--)
	{
		scanf("%s" , s);
		int len = strlen(s);
		sort(s , s+len);
		puts(s);
		while(next_permutation(s , s+len))puts(s);
		puts("");
	}
}
