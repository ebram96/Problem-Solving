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
typedef unsigned int ui;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//inline bool bin(string a , string b){return a > b;}
//inline bool bin(int a , int b){return a > b;}
//inline bool bin(ull a , ull b){return a > b;}
int a[10000];
inline bool bin(pairii y , pairii x)
{
	if( (a[x.second]%2==0)&& (a[y.second]%2))return 1;
	if( ((a[x.second]%2)&& (a[y.second]%2)) &&(a[x.second] < a[y.second]))return 1;
	if(((a[x.second]%2==0)&&(a[y.second]%2==0)) &&(a[x.second] > a[y.second]))return 1;
	return 0;
}
int main()
{
	//readf
	int n , m , cnt_tie , prev_y;
	pairii md[10000];
	while(scanf("%d %d" , &n , &m))
	{
		if(!n&&!m)break;
		fo(y , n)scanf("%d" , &a[y]) , md[y].first = a[y]%m , md[y].second = y;
		sort(md , md+n);
		cnt_tie = 1 , prev_y = 0;
		for(int y = 1 ; y < n ; y++)
			if(md[y].first == md[y-1].first)cnt_tie++;
			else
			{
				sort(md+prev_y , md+prev_y+cnt_tie , bin);
				cnt_tie = 1;
				prev_y = y;
			}
		sort(md+prev_y , md+prev_y+cnt_tie , bin);
		printf("%d %d\n" , n , m);
		fo(y , n)printf("%d\n" , a[md[y].second]);
	}
	puts("0 0");
}
