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
int n , a[30] , mars[1001][30][30] , ind , c , pre;
bool selected[30] , fail;
bool rec(int v,int i,int cnt)
{
	if(cnt>1&&!v)return 1;
	if(v<0||i<0)return 0;
	if(~mars[v][i][cnt])return mars[v][i][cnt];
	return mars[v][i][cnt] = (rec(v,i-1,cnt)||rec(v-a[i],i-1,cnt+1));
}
int main()
{
	//readf
	while(scanf("%d",&n)==1)
	{
		memset(mars,-1,sizeof(mars));
		scanf("%d",&a[0]);
		pre = a[0];
		ind = 0 , fail = 0;
		fo(1,y,n)
		{
			scanf("%d",&a[y]);
			if(a[y]<=pre)fail = 1;
			pre = a[y];
		}
		while(ind<n&&!fail)
		{
			fail|=rec(a[ind],ind-1,0);
			ind++;
		}
		printf("Case #%d:",++c);
		fo(0,y,n)printf(" %d",a[y]);
		puts(fail?"\nThis is not an A-sequence.":"\nThis is an A-sequence.");
	}
}

