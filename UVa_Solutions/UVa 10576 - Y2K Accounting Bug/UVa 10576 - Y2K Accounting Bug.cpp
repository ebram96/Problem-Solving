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
int dx[]={-1,-1,0,1,1, 1, 0,-1};
int dy[]={ 0, 1,1,1,0,-1,-1,-1};
bool a[12];
ll s , d , res;
inline bool valid()
{
	ll sum=0;
	fo(0,y,8)
	{
		sum&=~sum;
		fo(y,i,y+5)
			if(a[i])sum-=d;
			else sum+=s;
		if(sum>=0)return 0;
	}
	return 1;
}
int main()
{
	//readf
	int i=0,ds,dd;
	while(scanf("%lld%lld",&s,&d)==2)
	{
		memset(a,0,sizeof(a));
		i=11;
		res=(1<<31);
		while(i>=0)
		{
			do if(valid())
			{
				ds=dd=0;
				fo(0,y,12)
					if(a[y])dd++;
					else ds++;
				if(s*ds-d*dd>=0)res=max(res,s*ds-d*dd);
			}
			while(next_permutation(a,a+12));
			a[i--]=1;
		}
		if(res==(1<<31))puts("Deficit");
		else printf("%lld\n",res);
	}
}
