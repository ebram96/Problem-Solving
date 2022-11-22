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
int dx[]={-1,-1,0,1,1, 1, 0,-1};
int dy[]={ 0, 1,1,1,0,-1,-1,-1};
int t , a , b;
string p;
vector<string> res;
int main()
{
	//readf
	scanf("%d",&t);
	bool ok,line=0;
	wtm
	{
		scanf("%d%d",&a,&b);
		a-- , b--;
		p="01234567";
		do
		{
			ok=1;
			fo(0,x,8)
				for(int y=x+1;y<8;y++)
					if((y-x)==abs(p[y]-p[x]))
					{
						ok=0;
						y=x=8;
					}
			if(ok&&(p[b]==a+'0'))res.pb(p);
		}while(next_permutation(p.begin(),p.end()));
		sort(res.begin(),res.end());
		if(line)puts("");else line=1;
		puts("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8");
		fo(0,y,res.size())
		{
			printf("\n%2d     ",y+1);
			fo(0,k,8)printf(" %c",res[y][k]+1);
		}
		puts("");
		res.clear();
	}
}
