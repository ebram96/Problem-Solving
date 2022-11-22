//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<cstdint>
#include<iterator>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<bitset>
#include<stack>
#include<list>
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
#define mp make_pair
#define pairull pair<unsigned long long , unsigned long long>
#define seti set<int>
#define setpii set<pairii >
#define setull set<unsigned long long>
#define qint queue<int>
#define dqint deque<int>
#define pqint priority_queue<int>
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
	ui n , m , inp0 , inp1;
	while(scanf("%u %u" , &n , &m) == 2)
	{
		map<ui , vector<ui> >a;
		fo(y , n)scanf("%u" , &inp0) , a[inp0].pb(y+1);
		fo(y , m)
		{
			scanf("%u %u" , &inp0 , &inp1);
			//cout<<'\t'<<a[inp1].size()<<endl;
			if(a[inp1].empty() || (a[inp1].size()<inp0))
				puts("0");
			else printf("%u\n" , a[inp1][inp0-1]);
		}
	}
}
