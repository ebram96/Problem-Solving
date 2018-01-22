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
ll a[5] = {50,25,10,5,1} , mars[5][30001] , ways;
ll rec(int i,int val)
{
	if(!val)return 1;
	if(val<0||i==5)return 0;
	if(~mars[i][val])return mars[i][val];
	return mars[i][val]=rec(i+1,val)+rec(i,val-a[i]);
}
int main()
{
	//readf
	int amount;
	memset(mars,-1,sizeof(mars));
	while(scanf("%d",&amount)==1)
	{
		ways = rec(0,amount);
		if(ways==1)printf("There is only 1 way to produce %d cents change.\n",amount);
		else printf("There are %lld ways to produce %d cents change.\n",ways,amount);
	}
}

