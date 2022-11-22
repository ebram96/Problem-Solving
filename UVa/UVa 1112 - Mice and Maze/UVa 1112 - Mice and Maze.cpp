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
#define rallof(Z) Z.rbegin(),Z.rend()
#define mset(z,v) memset(z,v,sizeof(z))
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
//int dx[]={-1,0,1, 0,-1,1, 1,-1};
//int dy[]={ 0,1,0,-1, 1,1,-1,-1};
int main()
{
	//readf
	//solvable with Dijkstra's algorithm
	int T , t , n , m , e , u , v , w , apsp[100][100] , res;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&e,&t);
		fo(0,i,n)fo(0,j,n)apsp[i][j]=1e8;
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d %d %d",&u,&v,&w);
			apsp[u-1][v-1] = w;
		}
		fo(0,k,n)fo(0,i,n)fo(0,j,n)if(apsp[i][k]+apsp[k][j]<=t)
			apsp[i][j] = min(apsp[i][j],apsp[i][k]+apsp[k][j]);
		res = 0;
		fo(0,y,n)if(apsp[y][e-1]!=1e8)
			res++;
		printf("%d\n",res+1);
		if(T)puts("");
	}
}

