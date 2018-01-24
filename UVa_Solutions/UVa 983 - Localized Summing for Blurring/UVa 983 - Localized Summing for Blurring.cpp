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
int a[1000][1000] , res[1000][1000];
int main()
{
    //readf
	bool line = 0;
	int n , m;
	while(scanf("%d %d",&n,&m)==2)
	{
		for(int x = n-1 ; x>=0 ; x--)
			fo(0,y,n)
				scanf("%d",&a[x][y]);
		fo(0,x,n)fo(0,y,n)
		{
			if(x&&y)a[x][y]-=a[x-1][y-1];
			if(x)a[x][y]+=a[x-1][y];
			if(y)a[x][y]+=a[x][y-1];
		}
		m--;
		fo(0,x,n-m)fo(0,y,n-m)
		{
			res[x][y] = a[x+m][y+m];
			if(x&&y)res[x][y]+=a[x-1][y-1];
			if(x)res[x][y]-=a[x-1][y+m];
			if(y)res[x][y]-=a[x+m][y-1];
		}
		lne;
		ull sum = 0;
		for(int x = n-m-1 ; x>=0 ; x--)
			fo(0,y,n-m)
			printf("%d\n",res[x][y]) , sum+=res[x][y];
		printf("%llu\n",sum);
	}
}

