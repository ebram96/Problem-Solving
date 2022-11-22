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
typedef vector<string> vstr;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
int a[5];
bool res;
bool calc(int i,int sum)
{
	if(i==5)return sum==23;
	return calc(i+1,sum-a[i])||
			calc(i+1,sum*a[i])||
			calc(i+1,sum+a[i]);
}
int main()
{
	//readf
	while(scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4])&&a[0])
	{
		sort(a,a+5);
		res=0;
		do res=calc(1,a[0]);
		while(next_permutation(a,a+5)&&!res);
		puts(res?"Possible":"Impossible");
	}
}
