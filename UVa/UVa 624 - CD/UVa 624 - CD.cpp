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
int main()
{
	//readf
	int a[20] , n , l , res, sum , s , tmp , cnt , mx;
	while(scanf("%d%d",&l,&n)==2)
	{
		res=sum=mx=0;
		fo(0,y,n)scanf("%d",&a[y]);
		for(int i=0;i<(1<<n);i++)
		{
			s=tmp=cnt=0;
			for(int j=0;j<n;j++)
				if(i&(1<<j))s+=a[j],tmp|=(1<<j),cnt++;
			if((s<=l&&s>sum)||(s==sum&&cnt>mx))
				sum=s,res=tmp,mx=cnt;
		}
		fo(0,y,n)if((1<<y)&res)printf("%d ",a[y]);
		printf("sum:%d\n",sum);
	}
}
