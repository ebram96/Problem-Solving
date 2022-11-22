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
#define endl '\n'
#define fo(s , y , z) for(int y = s ; y < (int)z ; y++)
#define lne if(line)puts("");else line = 1;
#define pb push_back
#define pob pop_back
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
int t , mars[1000][31] , n , res , g , mw;
struct Obj{int p , w;};
Obj a[1000];
int rec(int i,int w)
{
	if(mars[i][w]!=-1)return mars[i][w];
	if(i==n||mw==w)return 0;
	int x=a[i].w+w<=mw?a[i].p+rec(i+1,w+a[i].w):0;
	return mars[i][w]=max(x,rec(i+1,w));
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		res = 0;
		scanf("%d",&n);
		fo(0,y,n)scanf("%d %d",&a[y].p,&a[y].w);
		scanf("%d",&g);
		fo(0,y,g)
		{
			memset(mars,-1,sizeof(mars));
			scanf("%d",&mw);
			res+=rec(0,0);
		}
		printf("%d\n",res);
	}
}

