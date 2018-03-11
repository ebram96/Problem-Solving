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
#define INF ~(1<<31)
#define endl '\n'
#define fo(s,y,z) for(int y=s ; y<(int)z ; y++)
#define pb push_back
#define pob pop_back
#define gcu getchar_unlocked
#define allof(Z) Z.begin(),Z.end()
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define lne if(line)puts("");else line =1
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pairii ;
typedef pair<ull,ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
ll calc(ll n)
{
	ll ret = 0;
	if(n>=100)ret+=200;
	else return 2*n;
	if(n>=101)ret+=(n>=10000?3*9900:(n-100)*3);
	if(n>=10001)ret+=(n>=1000000?5*(1e6-1e4):(n-1e4)*5);
	if(n>1e6)ret+=7*(n-1e6);
	return ret;
}
int main()
{
	//readf
	ll a , b , lo , hi , mid , fx , cons;
	while(scanf("%lld %lld",&a,&b)&&a)
	{
		lo = 0 , hi = 1e9;
		while(lo<=hi)
		{
			mid = (lo+hi)>>1;
			fx = calc(mid);
			if(fx==a)break;
			else if(fx<a)lo = mid+1;
			else hi = mid-1;
		}
		cons = mid;
		lo = 0 , hi = mid;
		ll val;
		while(lo<=hi)
		{
			mid = (lo+hi)>>1;
			val = calc(cons-mid)-calc(mid);
			if(val==b)break;
			else if(val>b)lo = mid+1;
			else hi = mid-1;
		}
		printf("%lld\n",calc(mid));
	}
}

