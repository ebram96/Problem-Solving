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
//int dx[]={-1,0,1, 0};
//int dy[]={ 0,1,0,-1};
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
int t , r , c , m , n , mars[100][100] , water[100][100] , w , C;
bool root , clrd[100][100];
inline bool valid(int x,int y)
{return x>=0&&y>=0&&x<r&&y<c&&water[x][y]==0;}
int dx[]={1, 1,-1,-1};
int dy[]={1,-1, 1,-1};
void dfs(int x,int y)
{
	if(~mars[x][y]||(root&&!(x||y))||clrd[x][y])return;
	root = 1;
	clrd[x][y] = 1;
	int cnt = 0 , newx , newy;
	set<pairii>s;
	fo(0,i,4)
	{
		newx = dx[i]*n+x , newy = dy[i]*m+y;
		if(valid(newx,newy)&&s.find({newx,newy})==s.end())
			 dfs(newx,newy),cnt++;
		s.insert({newx,newy});
		newx = dx[i]*m+x , newy = dy[i]*n+y;
		if(valid(newx,newy)&&s.find({newx,newy})==s.end())
			dfs(newx,newy),cnt++;
		s.insert({newx,newy});
	}
	mars[x][y] = cnt%2;
}
int main()
{
	//readf
	int odd , even , x , y;
	scanf("%d",&t);
	wtm
	{
		odd = even = root = 0;
		memset(mars,-1,sizeof(mars));
		memset(water,0,sizeof(water));
		memset(clrd,0,sizeof(clrd));
		scanf("%d %d %d %d %d",&r,&c,&m,&n,&w);
		fo(0,i,w)
		{
			scanf("%d %d",&x,&y);
			water[x][y] = 1;
		}
		dfs(0,0);
		fo(0,x,r)fo(0,y,c)if(~mars[x][y])
			(mars[x][y]?odd:even)++;
		printf("Case %d: %d %d\n",++C,even,odd);
	}
}

