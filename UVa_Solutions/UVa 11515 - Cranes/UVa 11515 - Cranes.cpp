//It's all about what U BELIEVE
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<bitset>
#include<vector>
#include<cstring>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define endl '\n'
#define PI acos(-1)
#define INF ~(1<<31)
#define pb push_back
#define pob pop_back
#define wtm while(t--)
#define wnm while(n--)
#define MOD 1000000007
#define lsone(Z) (Z&-Z)
#define gcu getchar_unlocked
#define allof(Z) Z.begin(),Z.end()
#define rallof(Z) Z.rbegin(),Z.rend()
#define mset(z,v) memset(z,v,sizeof(z))
#define lne if(line)puts("");else line =1
#define fo(s,y,z) for(int y=s ; y<(int)z ; y++)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,ull> pairull;
typedef pair<int,int> pairii;
typedef vector<string> vstr;
typedef deque<int> dqint;
typedef set<ull> setull;
typedef unsigned int ui;
typedef queue<int> qint;
typedef vector<int> vi;
typedef set<int> seti;
typedef long long ll;
//int dx[]={-1,0,1, 0,-1,1, 1,-1};
//int dy[]={ 0,1,0,-1, 1,1,-1,-1};
int n , x[15] , y[15] , r[15];
ll calculate(int msk)
{
	ll ret = 0 , dist;
	fo(0,i,n)if(msk & (1<<i))
	{
		fo(i+1,j,n)if(msk & (1<<j))
		{
			dist = 1LL*(x[j]-x[i])*(x[j]-x[i]) +
				   1LL*(y[j]-y[i])*(y[j]-y[i]) ;
			if(dist<=1LL*(r[i]+r[j])*(r[i]+r[j]))
				return 0;
		}
		ret += r[i] * r[i];
	}
	return ret;
}
int main()
{
	//readf
	int t;
	ll res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		fo(0,i,n)
			scanf("%d %d %d",&x[i],&y[i],&r[i]);
		res = 0;
		fo(0,msk,(1<<n))
			res = max(res , calculate(msk));
		printf("%lld\n",res);
	}
}
