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
#define PI acos(-1)
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
//int dx[]={-1,0,1, 0};
//int dy[]={ 0,1,0,-1};
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
int single , m , cnt[20] , price[20] , cs , mars[101];
int rec(int k)
{
	if(k<=0)return 0;
	int &ret = mars[k];
	if(~mars[k])return mars[k];
	ret = single+rec(k-1);
	fo(0,y,m)ret = min(ret,price[y]+rec(k-cnt[y]));
	return ret;
}
int main()
{
	//readf
	float inp;
	char c;
	int k;
	while(scanf("%f %d",&inp,&m)==2)
	{
		single = round(100*inp);
		fo(0,y,m)
		{
			scanf("%d %f",&cnt[y],&inp);
			price[y] = round(100*inp);
		}
		printf("Case %d:\n",++cs);
		memset(mars,-1,sizeof(mars));
		while(scanf(" %d",&k))
		{
			printf("Buy %d for $%.2f\n",k,rec(k)/100.0f);
			if(scanf("%c",&c)!=1||c=='\n')break;
		}
	}
}

