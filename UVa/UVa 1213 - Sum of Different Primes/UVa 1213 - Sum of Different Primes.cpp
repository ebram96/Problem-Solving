//It's all about what U BELIEVE
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<bitset>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#define endl '\n'
#define INF ~(1<<31)
#define pb push_back
#define pob pop_back
#define wtm while(t--)
#define wnm while(n--)
#define lsone(Z) (Z&-Z)
#define modulo 1000000007
#define gcu getchar_unlocked
#define allof(Z) Z.begin(),Z.end()
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
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
//int dx[]={-1,0,1, 0};
//int dy[]={ 0,1,0,-1};
vi v;
int p , n , k;
ll mars[187][187][1121];
ll rec(int i,int cnt,int val)
{
	if(!(val||cnt))return 1;
	if(val<0||i==p)return 0;
	if(~mars[i][cnt][val])return mars[i][cnt][val];
	return mars[i][cnt][val] = rec(i+1,cnt-1,val-v[i])+rec(i+1,cnt,val);
}
int main()
{
	//readf
	fo(2,y,1121)
	{
		float rt = sqrt(y);
		bool prime = 1;
		fo(2,i,rt+1)if(y%i==0)
		{
			prime = 0;
			break;
		}
		if(prime)v.pb(y);
	}
	p = v.size();
	memset(mars,-1,sizeof(mars));
	while(scanf("%d %d",&n,&k)&&n&&k)
		printf("%lld\n",rec(0,k,n));
}

