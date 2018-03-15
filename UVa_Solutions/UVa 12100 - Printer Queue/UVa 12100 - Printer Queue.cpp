//It's all about what U BELIEVE
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<bitset>
#include<vector>
#include<cstring>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define endl '\n'
#define PI acos(-1)
#define INF ~(1<<31)
#define pb push_back
#define pob pop_back
#define wtm while(t--)
#define wnm while(n--)
#define MOD 1000000007
#define lsone(Z) (Z&-Z)
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
	int t , n , m , res , paper , cnt[10] , mx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		res = mx = 0;
		queue<pair<int,bool> > q;
		mset(cnt , 0);
		fo(0,y,n)
		{
			scanf("%d",&paper);
			q.push({paper,y==m});
			cnt[paper]++;
			mx = max(mx , paper);
		}
		bool done = 0;
		while(!done)
			if(q.front().first == mx)
			{
				cnt[mx]--;
				while(!cnt[mx])
					mx--;
				if(q.front().second)
					done = 1;
				res++;
				q.pop();
			}
			else
				while(q.front().first != mx)
				{
					q.push(q.front());
					q.pop();
				}
		printf("%d\n",res);
	}
}



