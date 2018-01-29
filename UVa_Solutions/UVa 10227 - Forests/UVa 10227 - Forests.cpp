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
int tc , t , n , man , tree , res , p[100];
bool heard[100][100];
int getp(int a)
{return p[a]=(p[a]==a?a:getp(p[a]));}
void unit(int a , int b)
{
	int x = getp(a) , y = getp(b);
	if(x==y)return;
	p[x]=y;
	res--;
}
bool same_opinion(int a , int b)
{
	fo(1,y,100)if(heard[a][y]!=heard[b][y])
		return 0;
	return 1;
}
int main()
{
	//readf
	char inp[6];
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d %d",&n,&t);
		res = n;
		getchar();
		memset(heard,0,sizeof(heard));
		fo(1,y,100)p[y]=y;
		while(scanf("%[^\n]",inp)==1&&strcmp("\n",inp))
		{
			sscanf(inp,"%d %d",&man,&tree);
			heard[man][tree] = 1;
			getchar();
		}
		fo(1,y,n)fo(y+1,x,n+1)
			if(same_opinion(x,y))
				unit(x,y);
		printf("%d\n",res);
		if(tc)puts("");
	}
}
