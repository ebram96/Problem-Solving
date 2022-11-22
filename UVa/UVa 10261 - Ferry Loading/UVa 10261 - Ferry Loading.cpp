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
int t , n , mx , l[2000] , res;
bool side[201] , res_side[201], mars[201][10001] ;
void rec(int i,int left,int right)
{
	if(i>res)
	{
		res = i;
		copy(side,side+i,res_side);
	}
	if(i==n)return;
	if(mars[i][right])return;
	mars[i][right] = 1;
	if(l[i]+left<=mx)rec(i+1,left+l[i],right);
	if(l[i]+right<=mx)
	{
		side[i] = 1;
		rec(i+1,left,right+l[i]);
		side[i] = 0;
	}
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		n = res = 0;
		memset(side,0,sizeof(side));
		memset(mars,0,sizeof(mars));
		scanf("%d",&mx);
		mx*=100;
		while(scanf("%d",&l[n])&&l[n])n++;
		rec(0,0,0);
		printf("%d\n",res);
		fo(0,y,res)puts(!res_side[y]?"port":"starboard");
		if(t)puts("");
	}
}

