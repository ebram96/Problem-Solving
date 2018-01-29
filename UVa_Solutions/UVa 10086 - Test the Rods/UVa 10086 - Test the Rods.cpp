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
int T1,T2,n,m[30],a[30][21],b[30][21],cnt[30][301][301],mars[30][301][301];
int rec(int i,int t1,int t2)
{
	if(i==n)return t1==0&&t2==0?0:1e9;
	int &ret = mars[i][t1][t2];
	if(~ret)return mars[i][t1][t2];
	ret = INF;
	for(int y = 0 ,v ; y<=m[i]; y++)
		if(y<=t1&&m[i]-y<=t2)
		{
			v = rec(i+1,t1-y,t2-(m[i]-y))+a[i][y]+b[i][m[i]-y];
			if(v<ret)
			{
				cnt[i][t1][t2] = y;
				ret = v;
			}
		}
	return ret;
}
int main()
{
	//readf
	//writef
	while(scanf("%d %d",&T1,&T2)&&(T1||T2))
	{
		scanf("%d",&n);
		fo(0,i,n)
		{
			scanf("%d",&m[i]);
			fo(1,y,m[i]+1)scanf("%d",&a[i][y]);
			fo(1,y,m[i]+1)scanf("%d",&b[i][y]);
		}
		memset(mars,-1,sizeof(mars));
		//printf("%d\n%d",rec(0,T1,T2),cnt[0][T1][T2]);
		printf("%d",rec(0,T1,T2));
		printf("\n%d",cnt[0][T1][T2]);
		int pr = cnt[0][T1][T2];
		fo(1,y,n)
		{
			T1-=pr;
			T2-=m[y-1]-pr;
			pr = cnt[y][T1][T2];
			printf(" %d",cnt[y][T1][T2]);
		}
		puts("\n");
	}
}

