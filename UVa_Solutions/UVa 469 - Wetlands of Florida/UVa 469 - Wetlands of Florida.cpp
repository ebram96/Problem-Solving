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
int dx[]={-1,-1,0,1,1, 1, 0,-1};
int dy[]={ 0, 1,1,1,0,-1,-1,-1};
int t , n , m;
char grid[100][101];
bool lake[100][100];
bool valid(int &x,int &y)
{return x>=0&&x<n&&y>=0&&y<m;}
int ff(int x,int y)
{
	if(lake[x][y]||!valid(x,y)||grid[x][y]=='L')return 0;
	int ret = 1;
	lake[x][y] = 1;
	fo(0,i,8)
		ret+=ff(x+dx[i],y+dy[i]);
	return ret;
}
int main()
{
	//readf
	int x , y , res;
	scanf("%d",&t);
	wtm
	{
		n = 1;
		scanf("%s\n",grid[0]);
		m = strlen(grid[0]);
		while(scanf("%[^\n]",grid[n])==1)
		{
			if(isdigit(grid[n][0]))
			{
				memset(lake,0,sizeof(lake));
				sscanf(grid[n],"%d %d",&x,&y);
				printf("%d\n",res = ff(x-1,y-1));
			}
			//else if(grid[n][0]=='\n')break;
			else n++;
			getchar();
		}
		if(t)puts("");
	}
}

