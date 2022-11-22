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
int n , c , i , j , p[20000] , rnk[20000];
int getp(int node)
{return p[node]=(p[node]==node?node:getp(p[node]));}
void unit(int a , int b)
{
	int x = getp(a) , y = getp(b);
	if(x==y)return;
	if(rnk[x]>=rnk[y])
	{
		p[y] = x;
		rnk[x]+=(rnk[x]==rnk[y]);
	}
	else p[x] = y;
}
int main()
{
	//readf
	scanf("%d",&n);
	fo(0,y,2*n)p[y]=y , rnk[y]=1;
	while(scanf("%d %d %d",&c,&i,&j)&&c)
	{
		i*=2 , j*=2;
		// i*2 is my node , i+1 is the enemy of i
		if(c==1)
		{
			if(getp(i)==getp(j+1))
			{
				puts("-1");
				continue;
			}
			unit(i,j);
			unit(i+1,j+1);
		}
		else if(c==2)
		{
			if(getp(i)==getp(j))
			{
				puts("-1");
				continue;
			}
			unit(i,j+1);
			unit(i+1,j);
		}
		else if(c==3)puts(getp(i)==getp(j)?"1":"0");
		else puts(getp(i)==getp(j+1)?"1":"0");
	}
}
