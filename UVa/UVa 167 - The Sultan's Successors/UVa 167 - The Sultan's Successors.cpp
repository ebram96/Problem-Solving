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
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
int dx[]={-1,-1,0,1,1, 1, 0,-1};
int dy[]={ 0, 1,1,1,0,-1,-1,-1};
vi perm(8);
vector<vi> all;
int board[8][8] , sz , t , res , cmp;
inline bool valid()
{
	fo(0,y,8)
		fo(y+1,i,8)
			if(abs(perm[y]-perm[i])==i-y)
				return 0;
	return 1;
}
int main()
{
	//readf
	fo(0,y,8)perm[y]=y;
	do if(valid())all.pb(perm);
	while(next_permutation(perm.begin(),perm.end()));
	sz = all.size();
	scanf("%d",&t);
	wtm
	{
		fo(0,i,8)fo(0,j,8)
			scanf("%d",&board[i][j]);
		res = (1<<31);
		fo(0,y,sz)
		{
			cmp=0;
			fo(0,i,8)cmp+=board[i][all[y][i]];
			res = max(res,cmp);
		}
		printf("%5d\n",res);
	}
}
