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
int n , m , s , con[40] , tech[40] , mars[40][301][301];
int rec(int i,int x , int y)
{
	int mod = x*x+y*y;
	if(mod==s)return 0;
	if(mod>s||i==m)return 1e9;
	int &ret = mars[i][x][y];
	if(~ret)return ret;
	return ret = min(rec(i+1,x,y),1+rec(i,x+con[i],y+tech[i]));
}
int main()
{
	//readf
	scanf("%d",&n);
	wnm
	{
		scanf("%d %d",&m,&s);
		s*=s;
		fo(0,y,m)scanf("%d %d",&con[y],&tech[y]);
		memset(mars,-1,sizeof(mars));
		int res = rec(0,0,0);
		if(res!=1e9)printf("%d\n",res);
		else puts("not possible");
	}
}

