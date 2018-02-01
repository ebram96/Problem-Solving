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
#define INF ~(1<<31)
#define endl '\n'
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
int main()
{
	//readf
	int t , n , a[150][150] , sum , res;
	scanf("%d",&t);
	wtm
	{
		scanf("%d",&n);
		fo(0,x,n)fo(0,y,n)
		{
			scanf("%d",&a[x][y]);
			a[x][y+n] = a[x+n][y] = a[x+n][y+n] = a[x][y];
		}
		n<<=1;
		fo(0,x,n)fo(0,y,n)
		{
			if(x&&y)a[x][y]-=a[x-1][y-1];
			if(x)a[x][y]+=a[x-1][y];
			if(y)a[x][y]+=a[x][y-1];
		}
		n>>=1;
		res = -INF;
		fo(0,upx,n<<1)fo(0,upy,n<<1)
		{
			int e1 = min(upx+n,n<<1),e2 = min(upy+n,n<<1);
			fo(upx,downx,e1)fo(upy,downy,e2)
			{
				sum = a[downx][downy];
				if(upx&&upy)sum+=a[upx-1][upy-1];
				if(upx)sum-=a[upx-1][downy];
				if(upy)sum-=a[downx][upy-1];
				if(sum>res)res = sum;
			}
		}
		printf("%d\n",res);
	}
}

