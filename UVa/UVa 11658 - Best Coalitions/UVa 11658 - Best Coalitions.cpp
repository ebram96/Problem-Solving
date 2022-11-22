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
int n , ind , p[100];
bool mars[100][10001];
float res;
void rec(int i,int sum)
{
	if(sum>5000)
	{
		res = max(res,p[ind]/float(sum));
		return;
	}
	if(i==n)return;
	if(mars[i][sum])return;
	mars[i][sum] = 1;
	rec(i+1,sum);
	if(i!=ind)rec(i+1,sum+p[i]);
}
int main()
{
	//readf
	float perc;
	while(scanf("%d %d",&n,&ind)&&n)
	{
		fo(0,y,n)
		{
			scanf("%f",&perc);
			p[y] = round(perc*100);
		}
		memset(mars,0,sizeof(mars));
		res = 0;
		rec(0,p[--ind]);
		printf("%.2f\n",res*100);
	}
}

