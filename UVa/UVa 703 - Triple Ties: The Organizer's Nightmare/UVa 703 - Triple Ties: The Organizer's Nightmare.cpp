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
int n;
bool a[101][101];
vector<vi> res;
vi cyc(3);
inline bool draw(int &i,int &j,int &k)
{
	if(!(i<j&&j<k))return 0;
	return !(a[i][j]|a[i][k]|a[j][i]|a[j][k]|a[k][i]|a[k][j]);
}
inline bool cycle(int &i,int &j,int &k)
{
	if(!((i<j&&j<k)||(i>j&&j>k)))return 0;
	return a[i][j]&&a[j][k]&&a[k][i];
}
int main()
{
	//readf
	//(3 ≤ N ≤ 101)
	while(scanf("%d",&n)==1)
	{
		res.clear();
		fo(0,x,n)fo(0,y,n)
			scanf("%d",&a[x][y]);
		fo(0,i,n)fo(0,j,n)fo(0,k,n)
			if(draw(i,j,k)||cycle(i,j,k))
			{
				cyc[0] = i+1;
				cyc[1] = j+1;
				cyc[2] = k+1;
				res.pb(cyc);
			}
		int sz = res.size();
		printf("%d\n",sz);
		fo(0,y,sz)
			printf("%d %d %d\n",res[y][0],res[y][1],res[y][2]);
	}
}

