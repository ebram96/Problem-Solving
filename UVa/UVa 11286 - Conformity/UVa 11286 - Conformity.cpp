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
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define ull unsigned long long
#define pairii pair<int , int>
#define pairull pair<unsigned long long , unsigned long long>
#define seti set<int>
#define setull set<unsigned long long>
#define qint queue<int>
#define dqint deque<int>
#define pb push_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define non if(!n)break;
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
//bool bin(string a , string b){return a > b;}
//bool bina(int a , int b){return a > b;}
bool bin(ull a , ull b){return a > b;}
int main()
{
	readf
	int n , k;
	scanf("%d %d" , &n , &k);
	long inp;
	queue<long>seg;
	map<long , long>cnt;
	set<long>once;
	fo(y , k)
	{
		scanf("%ld" , &inp);
		seg.push(inp);
		cnt[inp]++;
		if(cnt[inp]==1)
			once.insert(inp);
		else if(cnt[inp]>1)
			once.erase(inp);
	}
	printf("%ld\n" , (*once.rend()));
	fo(y , n-k)
	{
		if(cnt[seg.front()]==1)
			once.erase(seg.front());
		cnt[seg.front()]--;
		if(cnt[seg.front()]==1)
			once.insert(seg.front());
		scanf("%ld" , &inp);
		seg.push(inp);
		cnt[inp]++;
		if(cnt[inp]==1)
			once.insert(inp);
		else if(cnt[inp]>1)
			once.erase(inp);
		if(!once.empty())
			printf("%ld\n" , (*once.rend()));
		else puts("nothing");
	}
}
