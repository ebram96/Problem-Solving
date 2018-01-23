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
int n,m,sz;
char dict[100][257],rule[257];
deque<string> out;
string str;
void print_output(int i)
{
	if(i==sz)
	{
		deque<string> tmp=out;
		str="";
		while(!tmp.empty())
			str+=tmp.front(),tmp.pop_front();
		puts(str.c_str());
		return;
	}
	if(rule[i]=='#')
		fo(0,y,n)
		{
			out.pb(dict[y]);
			print_output(i+1);
			out.pop_back();
		}
	else
		fo(0,y,10)
		{
			str="";
			str+=('0'+y);
			out.pb(str);
			print_output(i+1);
			out.pop_back();
			str="";
		}
}
int main()
{
	//readf
	while(scanf("%d",&n)==1)
	{
		fo(0,y,n)scanf("%s",dict[y]);
		scanf("%d",&m);
		puts("--");
		while(m--)
		{
			out.clear();
			scanf("%s",rule);
			sz=strlen(rule);
			print_output(0);
		}
	}
}
