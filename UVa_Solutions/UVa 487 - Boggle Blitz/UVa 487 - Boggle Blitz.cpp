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
int dx[]={-1,-1,0,1,1, 1, 0,-1};
int dy[]={ 0, 1,1,1,0,-1,-1,-1};
struct bin
{
	bool operator()(const string& b ,const string& a)
	{
		return a.size()==b.size()?a>b:a.size()>b.size();
	}
};
int n , t;
char board[20][20];
set<string,bin> res;
bool used[20][20];
inline bool valid(int& x , int& y)
{ return !(x<0||y<0||x==n||y==n); }
deque<char> str;
string get_str()
{
	string ret = "";
	int sz = str.size();
	fo(0,y,sz)ret+=str[y];
	return ret;
}
void rec(int x , int y , char pre)
{
	if((!valid(x,y))||used[x][y]||(pre>=board[x][y])||(str.size()>n*n))
		return;
	used[x][y]=1;
	str.pb(board[x][y]);
	if(str.size()>=3)res.insert(get_str());
	fo(0,i,8)rec(x+dx[i],y+dy[i],board[x][y]);
	str.pop_back();
	used[x][y]=0;
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		scanf("%d" , &n);
		fo(0,y,n)scanf("%s" , board[y]);
		res.clear();
		fo(0,x,n)fo(0,y,n)
		{
			memset(used,0,sizeof(used));
			str.clear();
			rec(x,y,0);
		}
		set<string,bin>::iterator s = res.begin() , e = res.end();
		while(s!=e)puts((*s++).c_str());
		if(t)puts("");
	}
}
