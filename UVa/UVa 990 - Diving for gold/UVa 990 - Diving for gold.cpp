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
int w , n , d[30] , v[30] , res , cnt;
bool mars[10001][30] , taken[30] , res_taken[30];
void rec(int t , int i)
{
    if(mars[t][i])return;
    if(i==n||!t)
    {
        int sum = 0;
        fo(0,y,n)if(taken[y])
                sum+=v[y];
        if(sum>res)
        {
            res = sum;
            cnt = 0;
            fo(0,y,n)
            {
                res_taken[y] = taken[y];
                cnt+=taken[y];
            }
        }
        return;
    }
    rec(t,i+1);
    if(3*w*d[i]<=t)
    {
        taken[i]=1;
        rec(t-3*w*d[i],i+1);
        taken[i]=0;
    }
}
int main()
{
    //readf
    int t;
    bool line = 0;
    while(scanf("%d %d",&t,&w)==2)
    {
        scanf("%d",&n);
        fo(0,y,n)scanf("%d %d",&d[y],&v[y]);
        res = 0;
        memset(mars , 0 , sizeof(mars));
        memset(taken , 0 , sizeof(taken));
        rec(t,0);
        lne;
        printf("%d\n%d\n",res,cnt);
        fo(0,y,n)if(res_taken[y])
            printf("%d %d\n",d[y],v[y]);
    }
}

