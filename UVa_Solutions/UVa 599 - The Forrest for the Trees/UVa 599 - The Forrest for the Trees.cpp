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
//size is 'Z'+1 = 91;
bool inp[91] , istree[91] , done[91];
int p[91] , tree , acorn , t;
int getp(int node)
{return p[node]=(p[node]==node?node:getp(p[node]));}
void unit(int a , int b)
{
	int x = getp(a) , y = getp(b);
	if(x==y)return;
	p[x] = y;
}
int main()
{
	//readf
	char i , j , prths , ast;
	scanf("%d",&t);
	wtm
	{
		fo('A',y,91)p[y]=y,istree[y]=inp[y]=done[y]=0;
		tree = acorn = 0;
		while(scanf(" %c",&prths)&&prths=='(')
		{
			scanf("%c,%c)",&i,&j);
			unit(i,j);
			istree[i]=istree[j]=1;
		}
		while((ast=gcu())&&(ast=='*'));//astrisks are useless
		while(scanf(" %c%c",&i,&j)==2)
		{
			inp[i]=1;
			if(j!=',')break;
		}
		inp[i]=1;
		fo('A',y,91)if(inp[y])
		{
			if(!istree[y])acorn++;
			else if(!done[getp(y)])tree++,done[getp(y)]=1;
		}
		printf("There are %d tree(s) and %d acorn(s).\n",tree,acorn);
	}
}
