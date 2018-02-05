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
int t , n , m , p , res;
int apsp[51][51] , dist[13][13] , mars[13][1<<13] , store[13] , diff[13];
float inp;
int tsp(int node,int mask)
{
	if(mask==(1<<p)-1)return 0;
	int &ret = mars[node][mask];
	if(~ret)return ret;
	ret = dist[node][0];
	fo(0,i,p)if(!(mask&(1<<i)))
		ret = min(ret,dist[node][i]-diff[i]+tsp(i,mask|(1<<i))+((mask|(1<<i))==(1<<p)-1)*dist[i][0]);
	return ret;
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		scanf("%d %d",&n,&m);
		n++;
		fo(0,i,n)fo(0,j,n)
			apsp[i][j] = (i==j?0:1e6);
		for(int i,j,y=0;y<m;y++)
		{
			scanf("%d %d %f",&i,&j,&inp);
			apsp[i][j] = min(apsp[i][j],int(round(100*inp)));
			apsp[j][i] = min(apsp[j][i],apsp[i][j]);
		}
		fo(0,k,n)fo(0,i,n)fo(0,j,n)//APSP
			apsp[i][j] = min(apsp[i][j],apsp[i][k]+apsp[k][j]);
		scanf("%d",&p);
		p++;
		fo(1,y,p)
		{
			scanf("%d %f",&store[y],&inp);
			diff[y] = round(100*inp);
		}
		fo(0,i,p)fo(0,j,p)
			dist[i][j] = apsp[store[i]][store[j]];
		memset(mars,-1,sizeof(mars));
		res = tsp(0,1);
		if(res>=0.0)puts("Don't leave the house");
		else printf("Daniel can save $%.2f\n",-res/100.0f);
	}
}

