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
int t , n , tot , a[20] , mars[20][201];
char c;
bool rec(int i,int sum)
{
	if(sum==(tot-sum))return 1;
	if(i==n||sum>(tot-sum))return 0;
	if(mars[i][sum]!=-1)return mars[i][sum];
	return mars[i][sum] = (rec(i+1,sum)||rec(i+1,sum+a[i]));
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		n = tot = 0;
		memset(mars,-1,sizeof(mars));
		while(scanf(" %d",&a[n]))
		{
			tot+=a[n];
			if(scanf("%c",&c)!=1||c!=' ')break;
			n++;
		}
		puts(rec(0,0)?"YES":"NO");
	}
}

