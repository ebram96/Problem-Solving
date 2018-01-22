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
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
//int dx[]={-1,0,1, 0};
//int dy[]={ 0,1,0,-1};
string s[999][18278];
char inp[1000];
int a[999][18278] , t , m , n;
bool ready[999][18278];
pairii get_loc(string ind)
{
	int x = 0, y = 0, pos = 0, pwr = 1, len = ind.size() , j;
	while(!isdigit(ind[pos]))pos++;
	j = pos-1;
	while(pos<len)
	{
		x*=10;
		x+=ind[pos++]-'0';
	}
	x--;//zero indexed
	while(j>=0)
	{
		y+=(ind[j]-'A'+1)*pwr;
		pwr*=26;
		j--;
	}
	y--;//zero indexed
	return {x,y};
}
int dfs(int x,int y)
{
	if(ready[x][y])return a[x][y];
	ready[x][y] = 1;
	pairii location;
	int val = 0, sz = s[x][y].size();
	string ind;
	fo(1,i,sz)
		if(isalpha(s[x][y][i])||isdigit(s[x][y][i]))
			ind+=s[x][y][i];
		else
		{
			location = get_loc(ind);
			val+=dfs(location.first,location.second);
			ind = "";
		}

	location = get_loc(ind);
	val+=dfs(location.first,location.second);
	return a[x][y] = val;
}
int main()
{
	//pairii p = get_loc("ZZZ1");
	//cout<<p.first<<" "<<p.second;
	//readf
	//writef
	scanf("%d",&t);
	wtm
	{
		scanf("%d %d",&m,&n);
		fo(0,x,n)fo(0,y,m)
			if(scanf("%d",&a[x][y])!=1)
			{
				scanf("%s",inp);
				s[x][y] = inp;
				ready[x][y] = 0;
			}
			else ready[x][y] = 1;
		fo(0,x,n)
		{
			printf("%d",dfs(x,0));
			fo(1,y,m)printf(" %d",dfs(x,y));
			puts("");
		}
	}
}

