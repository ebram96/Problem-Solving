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
int n , m , c , g[21][21] , k[21] , mars[201][21] , money , res;
int rec(int i)
{
	if(i==c)
	{
		res = max(res,m-money);
		return 0;
	}
	if(mars[money][i]!=-1)return mars[money][i];
	int &ret = mars[money][i];
	fo(0,y,k[i])if(money>=g[i][y])
	{
		money-=g[i][y];
		ret = max(ret,rec(i+1));
		money+=g[i][y];
	}
	return ret;
}
int main()
{
	//readf
	scanf("%d",&n);
	wnm
	{
		res = -1;
		scanf("%d%d",&m,&c);
		fo(0,y,c)
		{
			scanf("%d",&k[y]);
			fo(0,i,k[y])scanf("%d",&g[y][i]);
		}
		memset(mars,-1,sizeof(mars));
		money = m;
		rec(0);
		if(res!=-1)printf("%d\n",res);
		else puts("no solution");
	}
}

