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
int t , amount , n , a[100] , mars[100][10001];
int rec_payment(int i,int val)
{
	if(val>=amount)return val-amount;
	if(i==n)return 1e9;
	if(~mars[i][val])return mars[i][val];
	return mars[i][val] = min(rec_payment(i+1,val+a[i]),rec_payment(i+1,val));
}
int rec_coin(int i,int val)
{
	if(!val)return 0;
	if(val<0||i==n)return 1e9;
	if(~mars[i][val])return mars[i][val];
	return mars[i][val] = min(1+rec_coin(i+1,val-a[i]),rec_coin(i+1,val));
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		scanf("%d %d",&amount,&n);
		fo(0,y,n)scanf("%d",&a[y]);
		memset(mars,-1,sizeof(mars));
		int diff = rec_payment(0,0);
		memset(mars,-1,sizeof(mars));
		printf("%d %d\n",diff+amount,rec_coin(0,diff+amount));
	}
}

