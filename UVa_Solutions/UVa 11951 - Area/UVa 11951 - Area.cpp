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
int main()
{
	//readf
	ll t , n , m , k , c = 1 , area , p[100][100] , cost , sub_area , sub_cost;
	scanf("%lld",&t);
	wtm
	{
		scanf("%lld %lld %lld",&n,&m,&k);
		fo(0,x,n)fo(0,y,m)
		{
			scanf("%lld",&p[x][y]);
			if(x&&y)p[x][y]-=p[x-1][y-1];
			if(x)p[x][y]+=p[x-1][y];
			if(y)p[x][y]+=p[x][y-1];
		}
		area = 0 , cost = INF;
		fo(0,upx,n)fo(0,upy,m)
			fo(upx,downx,n)fo(upy,downy,m)
			{
				sub_cost = p[downx][downy];
				if(upx&&upy)sub_cost+=p[upx-1][upy-1];
				if(upx)sub_cost-=p[upx-1][downy];
				if(upy)sub_cost-=p[downx][upy-1];
				sub_area = (downx-upx+1)*(downy-upy+1);
				if(sub_cost>k)break;
				if(sub_area>=area)
				{
					cost = (sub_area==area?min(cost,sub_cost):sub_cost);
					area = sub_area;
				}
			}
		printf("Case #%lld: %lld %lld\n",c++,area,(area?cost:0));
	}
}

