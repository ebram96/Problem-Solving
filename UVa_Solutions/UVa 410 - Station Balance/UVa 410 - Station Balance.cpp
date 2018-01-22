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
//int dx[]={-1,0,1, 0};
//int dy[]={ 0,1,0,-1};
int main()
{
	//readf
	int c , s , inp , tc = 1;
	vi v;
	double imb , cm , am , tot;
	while(scanf("%d %d",&c,&s)==2)
	{
		v.clear();
		tot = imb = 0.0;
		fo(0,y,s)
		{
			scanf("%d",&inp);
			tot+=inp;
			v.pb(inp);
		}
		am = tot/c;
		while(v.size()<2*c)v.pb(0);
		sort(allof(v));
		printf("Set #%d\n",tc++);
		int i = 0;
		fo(0,y,c)
		{
			cm = 0.0;
			printf("%2d:",y);
			if(v[i])printf(" %d",v[i]),cm+=v[i];
			if(v[2*c-i-1])printf(" %d",v[2*c-i-1]);
			cm+=v[2*c-i-1];
			imb+=fabs(cm-am);
			i++;
			puts("");
		}
		printf("IMBALANCE = %.5lf\n\n",imb);
	}
}

