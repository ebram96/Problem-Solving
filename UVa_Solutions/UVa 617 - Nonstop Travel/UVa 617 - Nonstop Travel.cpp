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
struct sign
{
	float d;
	int r , gy;
};
int main()
{
	//readf
	sign a[6];
	int n,green,yellow,red,c=1,s,e,accepted,valid;
	bool res[61];
	float t;
	while(scanf("%d",&n)&&n!=-1)
	{
		accepted = 0;
		memset(res,0,sizeof(res));
		fo(0,y,n)
		{
			scanf("%f %d %d %d",&a[y].d,&green,&yellow,&red);
			a[y].gy = green+yellow;
			a[y].r = green+yellow+red;
		}
		fo(30,v,61)
		{
			valid = 0;
			fo(0,y,n)
			{
				t = fmod(a[y].d/v*3600,a[y].r);
				if(t<=a[y].gy)valid++;
				else break;
			}
			if(valid==n)
			{
				res[v] = 1;
				accepted++;
			}
		}
		printf("Case %d: ",c++);
		if(!accepted)
		{
			puts("No acceptable speeds.");
			continue;
		}
		fo(30,y,61)if(res[y])
		{
			s = e = y;
			while(e<61&&res[e])
				e++,accepted--;
			e--;
			if(s==e)printf("%d",s);
			else printf("%d-%d",s,e);
			if(accepted)printf(", ");
			y = e+1;
		}
		puts("");
	}
}

