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
int dx[]={-1,-1,0,1,1, 1, 0,-1};
int dy[]={ 0, 1,1,1,0,-1,-1,-1};
int main()
{
	//readf
	int l , r , h , a[10001] , pre_h , init_y;
	memset(a,0,sizeof(a));
	scanf("%d%d%d",&l,&h,&r);
	init_y=l;
	do fo(l,y,r)a[y]=max(a[y],h);
	while(scanf("%d%d%d",&l,&h,&r)==3);
	printf("%d %d",init_y,a[init_y]);
	pre_h=a[init_y];
	fo(1,y,10001)
		if(a[y]!=pre_h)
			printf(" %d %d",y,a[y]),pre_h=a[y];
	puts("");
}
