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
int n , w[1000] , l[1000] , mars[1000][3001];
int rec(int i,int mn)
{
	if(i==n)return 0;
	if(mn!=INF&&~mars[i][mn])return mars[i][mn];
	int ret = -1;
	if(mn>=w[i])
		ret = max(ret,rec(i+1,(l[i]<mn-w[i]?l[i]:mn-w[i]))+1);
	ret = max(ret,rec(i+1,mn));
	if(mn==INF)mn = l[i];
	return mars[i][mn] = ret;
}
int main()
{
	//readf
	while(scanf("%d",&n)&&n)
	{
		fo(0,y,n)scanf("%d %d",&w[y],&l[y]);
		memset(mars,-1,sizeof(mars));
		printf("%d\n",rec(0,INF));
	}
}

