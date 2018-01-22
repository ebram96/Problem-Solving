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
char inp[12] , a[7] , b[7];
map<string , bool>m;
void generate(string s)
{
	if(m[s])return;
	m[s]=1;
	string par = s;
	char shift;
	//horizontal :
	shift = par[3];
	for(int y = 3 ; y > 0 ; y--)
		par[y] = par[y-1];
	par[0] = shift;
	generate(par);
	//vertical :
	shift = s[4];
	swap(s[3],s[5]);
	swap(s[1],s[5]);
	swap(s[4],s[1]);
	generate(s);
}
void order_s(char* s)
{
	char cop[7];
	cop[6] = 0;
	cop[0] = s[2];
	cop[1] = s[1];
	cop[2] = s[3];
	cop[3] = s[4];
	cop[4] = s[0];
	cop[5] = s[5];
	strcpy(s , cop);
}
int main()
{
	//readf
	while(scanf("%s",inp)==1)
	{
		m.clear();
		fo(0,y,6)a[y]=inp[y];
		a[6] = b[6] = 0;
		fo(6,y,12)b[y-6]=inp[y];
		order_s(a);
		order_s(b);
		generate(a);
		puts(m[b]?"TRUE":"FALSE");
	}
}

