//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
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
#define pb push_back
#define pob pop_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
bool dig[10];
inline bool valid(ll v)
{
	memset(dig,0,sizeof(dig));
	while(v)
	{
		if(dig[v%10])return 0;
		dig[v%10]=1;
		v/=10;
	}
	return 1;
}
int main()
{
	//readf
	int t;
	ll n , s1 , s2;
	scanf("%d",&t);
	wtm
	{
		scanf("%lld",&n);
		for(s2 = 1;s2*n<=9876543210;s2++)
		{
			s1 = s2*n;
			if((s1/s2!=n)||!(valid(s1)&&valid(s2)))continue;
			printf("%lld / %lld = %lld\n",s1,s2,n);
		}
		if(t)putchar_unlocked('\n');
	}
}

