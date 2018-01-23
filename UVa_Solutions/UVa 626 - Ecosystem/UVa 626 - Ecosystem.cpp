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
#define INF ~(1<<31)
#define endl '\n'
#define fo(s , y , z) for(int y = s ; y < (int)z ; y++)
#define pb push_back
#define pob pop_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define lne if(line)puts("");else line =1
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pairii ;
typedef pair<ull,ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
//int dx[]={-1,0,1, 0};
//int dy[]={ 0,1,0,-1};
int n , res , cycle[3] , start;
bool a[100][100];
bool sorted()
{
	if(cycle[0]<cycle[1]&&cycle[1]<cycle[2])return 1;
	return (cycle[0]>cycle[1]&&cycle[1]>cycle[2]);
}
void rec(int node,int depth)
{
	if(depth==3)
	{
		if(sorted()&&node==start)
			printf("%d %d %d\n",cycle[0],cycle[1],cycle[2]),res++;

		return;
	}
	cycle[depth]=node+1;
	fo(0,y,n)if(a[node][y])
		rec(y,depth+1);
}
int main()
{
	//readf
	while(scanf("%d",&n)==1)
	{
		res = 0;
		fo(0,x,n)fo(0,y,n)
			scanf("%d",&a[x][y]);
		fo(0,y,n)
		{
			start = y;
			rec(y,0);
		}
		printf("total:%d\n\n",res);
	}
}

