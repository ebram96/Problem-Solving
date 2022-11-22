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
int n , c;
vi circ(16);
bool used[17] , line;
bool is_prime(int num)
{
	int rt = sqrt(num);
	fo(2,y,rt+1)if(!(num%y))return 0;
	return 1;
}
void traverse(int i)
{
	if(i==n)
	{
		if(is_prime(1+circ[n-1]))
		{
			printf("1");
			fo(1,i,n)printf(" %d",circ[i]);
			puts("");
		}
		return ;
	}
	fo(2,y,n+1)if((!used[y])&&is_prime(circ[i-1]+y))
	{
		circ[i]=y;
		used[y]=1;
		traverse(i+1);
		used[y]=0;
	}
}
int main()
{
	//readf
	circ[0]=1;
	while(scanf("%d",&n)==1)
	{
		memset(used,0,sizeof(used));
		lne
		printf("Case %d:\n",++c);
		traverse(1);
	}
}
