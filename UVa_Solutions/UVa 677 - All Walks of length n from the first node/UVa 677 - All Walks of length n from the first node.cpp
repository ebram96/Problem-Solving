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
bool exists , adj[10][10],done[10];
int n , w , sz;
dqint path;
void traverse(int node,int level)
{
	if(done[node])return;
	path.pb(node);
	if(level==w)
	{
		exists=1;
		dqint tmp = path;
		sz = tmp.size();
		putchar_unlocked('(');
		while(sz--)
		{
			printf("%d",tmp.front()+1);
			tmp.pop_front();
			if(sz)putchar_unlocked(',');
		}
		puts(")");
		path.pop_back();
		return ;
	}
	fo(0,y,n)if(adj[node][y])
	{
		done[node]=1;
		traverse(y,level+1);
		done[node]=0;
	}
	path.pop_back();
}
int main()
{
	//readf
	while(scanf("%d%d",&n,&w)==2)
	{
		exists=0;
		memset(done,0,sizeof(done));
		while(!path.empty())path.pop_back();
		fo(0,i,n)fo(0,j,n)
			scanf("%d",&adj[i][j]);
		traverse(0,0);
		if(!exists)printf("no walk of length %d\n",w);
		scanf("%d",&w);
		if(w==-9999)puts("");
	}
}
