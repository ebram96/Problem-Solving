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
struct Piece
{
	int l , r;
};
Piece pcs[14];
int n , m , l , r, ignr;
bool res,used[14];
void traverse(int i,int& l , int& r)
{
	if(res||i==n)
	{
		if(r==l)res=1;
		return;
	}
	int valid=-1,prev_l;
	fo(0,y,m)if(!used[y])
	{
		valid=-1;
		if(pcs[y].l==l)valid=1;
		else if(pcs[y].r==l)valid=0;
		if(valid==-1)continue;
		prev_l = l;
		l = (valid?pcs[y].r:pcs[y].l);
		used[y]=1;
		traverse(i+1,l,r);
		used[y]=0;
		l = prev_l;
	}
}
int main()
{
	//readf
	while(scanf("%d",&n)&&n)
	{
		res=0;
		scanf("%d%d%d%d%d",&m,&ignr,&l,&r,&ignr);
		memset(used,0,sizeof(used));
		fo(0,y,m)scanf("%d%d",&pcs[y].l,&pcs[y].r);
		traverse(0,l,r);
		puts(res?"YES":"NO");
	}
}
