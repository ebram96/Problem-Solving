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
#define INF ~(1<<31)
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
int t , r , h , res , tp[20] , rp[20] , hp[20] , inp , rest,resr,resh;
bool ta[20][20] , ra[20][20] , ha[20][20];
inline bool valid(int i,int j,int k)
{return !(ta[i][j]|ra[j][k]|ha[k][i]);}
int main()
{
	//readf
	while(scanf("%d %d %d",&t,&r,&h)==3)
	{
		memset(ta,0,sizeof(ta));
		memset(ha,0,sizeof(ta));
		memset(ra,0,sizeof(ta));
		res = INF;
		fo(0,z,t)
		{
			scanf("%d",&tp[z]);
			fo(0,y,r)scanf("%d",&ta[z][y]);
		}
		fo(0,z,r)
		{
			scanf("%d",&rp[z]);
			fo(0,y,h)scanf("%d",&ra[z][y]);
		}
		fo(0,z,h)
		{
			scanf("%d",&hp[z]);
			fo(0,y,t)scanf("%d",&ha[z][y]);
		}
		fo(0,i,t)fo(0,j,r)fo(0,k,h)if(valid(i,j,k))
			if(tp[i]+rp[j]+hp[k]<res)
			{
				res = tp[i]+rp[j]+hp[k];
				rest = i;
				resr = j;
				resh = k;
			}
		if(res==INF)puts("Don't get married!");
		else printf("%d %d %d:%d\n",rest,resr,resh,res);
	}
}

