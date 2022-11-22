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
#define pb push_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define non if(!n)break;
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//inline bool bin(string a , string b){return a > b;}
//inline bool bin(int a , int b){return a > b;}
//inline bool bin(ull a , ull b){return a > b;}
int main()
{
	//readf
	int n , m , a[1000] , sum , inp , c = 1 , dif;
	while(scanf("%d" , &n))
	{
		non
		fo(y , n)scanf("%d" , &a[y]);
		scanf("%d" , &m);
		printf("Case %d:\n" , c++);
		fo(y , m)
		{
			scanf("%d" , &inp);
			dif |= ~(1<<31);
			fo(y , n)fo(i , n)
			{
				if(i!=y && (abs(inp-(a[i]+a[y])) < dif))
					dif = abs(inp-(a[i]+a[y])) , sum = a[i] + a[y];
			}
			printf("Closest sum to %d is %d.\n" , inp , sum);
		}
	}
}
