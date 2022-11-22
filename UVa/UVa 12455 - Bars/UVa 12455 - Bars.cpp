//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<cstring>
#include<cmath>
#include<set>
#define endl '\n'
#define fo(s , y , z) for(int y = s ; y < (int)z ; y++)
#define lne if(line)puts("");else line = 1;
#define pb push_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define non if(!n)break;
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
int a[20] , n , t , p;
bool rec(int i , int sofar)
{
	if(sofar==n)return 1;
	if(i==p||sofar>n)return 0;
	return rec(i+1,sofar+a[i])||rec(i+1,sofar);
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		scanf("%d%d",&n,&p);
		fo(0,y,p)scanf("%d",&a[y]);
		puts(rec(0,0)?"YES":"NO");
	}
}
