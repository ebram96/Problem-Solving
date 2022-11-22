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
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
//int dx[]={-1,0,1, 0};
//int dy[]={ 0,1,0,-1};
int t , n , x[11] , y[11] , dist[11][11] , mars[11][1<<11];
int tsp(int node,int mask)
{
	if(mask==(1<<n)-1)return 0;
	int &ret = mars[node][mask];
	if(~ret)return ret;
	ret = INF;
	fo(0,i,n)if(!((1<<i)&mask))
		ret = min(ret,dist[node][i]+tsp(i,mask|(1<<i))+((mask|(1<<i))==(1<<n)-1)*dist[i][0]);
	return ret;
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		scanf("%d %d",&x[0],&y[0]);//useless input
		scanf("%d %d %d",&x[0],&y[0],&n);
		n++;
		fo(1,i,n)scanf("%d %d",&x[i],&y[i]);
		fo(0,i,n)fo(0,j,n)
			dist[i][j] = abs(x[i]-x[j])+abs(y[i]-y[j]);
		memset(mars,-1,sizeof(mars));
		printf("The shortest path has length %d\n",tsp(0,1));
	}
}

