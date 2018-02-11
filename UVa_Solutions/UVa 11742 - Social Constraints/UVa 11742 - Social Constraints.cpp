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
#define non if(!n)break;
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
struct cnstrn{int a , b , c;};
vector<cnstrn> v;
int n , m , a[8] , res = 0;
inline bool valid()
{
	fo(0,y,m)
		if( abs(a[v[y].a]-a[v[y].b])<-1*v[y].c)return 0;
		else if(v[y].c>0 &&abs(a[v[y].a]-a[v[y].b])>v[y].c)return 0;
	return 1;
}
int main()
{
	//readf
	cnstrn con;
	while(scanf("%d %d" , &n , &m) && n)
	{
		v.clear();
		res = 0;
		fo(0,y,n)a[y] = y;
		fo(0,y,m)scanf("%d %d %d" , &con.a , &con.b , &con.c),v.pb(con);
		do
		{
			res+=valid();
		}while(next_permutation(a , a+n));
		printf("%d\n" , res);
	}
}

