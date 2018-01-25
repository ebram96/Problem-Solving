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
#define clr(z,v) memset(z,v,sizeof(z))
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
int dx[]={-1,0,1, 0,-1,1, 1,-1};
int dy[]={ 0,1,0,-1, 1,1,-1,-1};
map<char,int>HEX;
int h , w , c , ind , dig , cnt_white_comp;
bool grid[200][200] , filled[200][200];
string res;
char inp;
void fill_white(int x,int y)
{
	if(!(x<h&&x>=0&&y<w&&y>=0)||filled[x][y]||grid[x][y])return;
	filled[x][y] = 1;
	fo(0,i,8)fill_white(x+dx[i],y+dy[i]);
}
void fill_black(int x,int y)
{
	if(!(x<h&&x>=0&&y<w&&y>=0)||filled[x][y])return;
	if(!grid[x][y])
	{
		fill_white(x,y);
		cnt_white_comp++;
		return;
	}
	filled[x][y] = 1;
	fo(0,i,8)fill_black(x+dx[i],y+dy[i]);
}
int main()
{
	//readf
	for(char i = '0';i<='9';i++)
		HEX[i] = i-'0';
	for(char i = 'a';i<='f';i++)
		HEX[i] = i-'a'+10;
	while(scanf("%d %d",&h,&w)&&h)
	{
		clr(grid,0);
		clr(filled,0);
		res.clear();
		fo(0,i,h)
		{
			ind = 0;
			fo(0,j,w)
			{
				scanf(" %c",&inp);
				dig = HEX[inp];
				for(int y = ind+3 ; y>=ind ; y--)
				{
					grid[i][y] |= (dig&1);
					dig>>=1;
				}
				ind+=4;
			}
		}
		w*=4;
		fo(0,x,h)fill_white(x,0) , fill_white(x,w-1);
		fo(0,y,w)fill_white(0,y) , fill_white(h-1,y);
		fo(0,x,h)fo(0,y,w)if(grid[x][y]&&!filled[x][y])
		{
			cnt_white_comp = 0;
			fill_black(x,y);
			if(!cnt_white_comp)res.pb('W');
			else if(cnt_white_comp==1)res.pb('A');
			else if(cnt_white_comp==2)res.pb('K');
			else if(cnt_white_comp==3)res.pb('J');
			else if(cnt_white_comp==4)res.pb('S');
			else res.pb('D');
		}
		sort(allof(res));
		printf("Case %d: %s\n",++c,res.c_str());
	}
}

