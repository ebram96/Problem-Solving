//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<cstring>
#include<cmath>
#include<set>
#define endl '\n'
#define fo(s , y , z) for(int y = s ; y < (int)z ; y++)
#define lne if(line)puts("");else line = 1;
#define pb push_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define non if(!n)break;
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
ull get_kth(ull d , ull k)
{
	ull i , sum = 0;
	for(i = 1; sum < k ; sum+=d*i++);
	return i-1;
}
int main()
{
	//readf
	ull c[21] , v , deg , d , k , t , res;
	scanf("%llu",&t);
	wtm
	{
		res=0;
		scanf("%llu",&deg);
		fo(0,y,deg+1)scanf("%llu",&c[y]);
		scanf("%llu %llu",&d,&k);
		v = get_kth(d,k);
		fo(0,y,deg+1)res+=c[y]*pow(v,y);
		printf("%llu\n",res);
	}
}

