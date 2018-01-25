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
int len , n , a[51] , mars[51][51];
int rec(int l,int r)
{
	if(l+1==r)return 0;
	int &ret = mars[l][r];
	if(~ret)return ret;
	ret = INF;
	fo(l+1,y,r)
		ret = min(ret,rec(l,y)+rec(y,r)+a[r]-a[l]);
	return ret;
}
int main()
{
	//readf
	while(scanf("%d",&len)&&len)
	{
		memset(mars,-1,sizeof(mars));
		scanf("%d",&n);
		a[0] = 0 , a[n+1] = len;
		fo(1,y,n+1)scanf("%d",&a[y]);
		printf("The minimum cutting is %d.\n",rec(0,n+1));
	}
}

