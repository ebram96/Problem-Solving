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
ll s , d , tot , res;
void backtrack(int i , ll sum)
{
	if(i<=4)
	{
		backtrack(i+1,sum+s);//add surplus
		a[i]=1;
		backtrack(i+1,sum-d);//remove deficit
		a[i]=0;
		return;
	}
	if(sum>=0)return;//sum of 5 consecutive months
	if(i==12)
	{
		tot &= ~tot;
		fo(0,y,12)
			if(a[y])tot-=d;
			else tot+=s;
		res = max(res , tot);
		return;
	}
	//try two possibilities
	backtrack(i+1,a[i-5]?d+sum+s:sum);//add surplus
	a[i]=1;
	backtrack(i+1,a[i-5]?sum:sum-d+s);//remove deficit
	a[i]=0;
}
int main()
{
	//readf
	while(scanf("%lld%lld",&s,&d)==2)
	{
		res=(1<<31);
		backtrack(0,0);
		if(res<=0)puts("Deficit");
		else printf("%lld\n",res);
	}
}
