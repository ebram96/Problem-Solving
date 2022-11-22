//It's all about what U BELIEVE
/*
#include<iostream>
#include<vector>
#include<cstdint>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<bitset>
#include<tuple>
#include<cstring>
#include<cmath>
#include<unordered_map>
#include<climits>
#include<set>
#include<unordered_set>
*/
#include<bits/stdc++.h>
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define ull unsigned long long
#define pairii pair<int , int>
#define pairull pair<unsigned long long , unsigned long long>
#define seti set<int>
#define setull set<unsigned long long>
#define pb push_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define non if(!n)break;
#define frop freopen("/home/ebram96/Desktop/in" , "r" , stdin);	freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
//bool bin(string a , string b){return a > b;}
//bool bina(int a , int b){return a > b;}
bool bin(ull a , ull b){return a > b;}
int main()
{
	frop
	char c , prev_key;
	string str = "" , cop = "";
	while(scanf("%c" , &c)==1)
	{
		if(c == '\n')
		{
			if(prev_key==']')
				str.insert(str.length() , cop);
			else
				str.insert(0 , cop);
			cop = "";
			if(str.length())
				puts(str.c_str());
			str = "";
			continue;
		}
		else if(c!='['&&c!=']')
			cop+=c;
		else
		{
			if(prev_key==']')
				str.insert(str.length() , cop);
			else
				str.insert(0 , cop);
			cop = "";
			prev_key = c;
		}
	}
	if(prev_key==']')
		str.insert(str.length() , cop);
	else
		str.insert(0 , cop);
	if(str.length())
		puts(str.c_str());
}
