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
int main()
{
	//readf
	int n , m , t , mars[10001];
	while(scanf("%d %d %d",&n,&m,&t)==3)
	{
		memset(mars,-1,sizeof(mars));
		mars[0] = 0;
		fo(1,y,t+1)
		{
			if(y>=n&&~mars[y-n])mars[y] = max(mars[y],1+mars[y-n]);
			if(y>=m&&~mars[y-m])mars[y] = max(mars[y],1+mars[y-m]);
		}
		if(~mars[t])printf("%d\n",mars[t]);
		else for(int i = t ; i>=0 ; i--)
			if(~mars[i])
			{
				printf("%d %d\n",mars[i],t-i);
				break;
			}
	}
}

