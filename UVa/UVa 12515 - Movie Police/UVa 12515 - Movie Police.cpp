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
char a[1000][101] , clip[101];
int n , q , clen , mlen , max_similar , similar , res;
int main()
{
	//readf
	scanf("%d %d",&n,&q);
	fo(0,y,n)scanf("%s",a[y]);
	while(q--)
	{
		max_similar = 0;
		scanf("%s",clip);
		clen = strlen(clip);
		fo(0,y,n)
		{
			mlen = strlen(a[y]);
			if(max_similar==clen)break;
			fo(0,i,mlen-clen+1)
			{
				similar = 0;
				if(max_similar==clen)break;
				for(int j = i ; j-i < clen ;j++)
				if(clip[j-i]==a[y][j])
					similar++;
				if(similar>max_similar)
				{
					res = y;
					max_similar = similar;
				}
			}
		}
		printf("%d\n",res+1);
	}
}

