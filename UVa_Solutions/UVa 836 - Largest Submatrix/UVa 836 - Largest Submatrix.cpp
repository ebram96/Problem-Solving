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
#define fo(s,y,z) for(int y=s ; y<(int)z ; y++)
#define pb push_back
#define pob pop_back
#define gcu getchar_unlocked
#define allof(Z) Z.begin(),Z.end()
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
int main()
{
    //readf
    char buff[25][26];
    int a[25][25];
    int t, n , res , sum;
    scanf("%d", &t);
    wtm
    {
        scanf("%s",buff[0]);
        n = strlen(buff[0]);
        fo(1,y,n)scanf("%s",buff[y]);
        fo(0,x,n)fo(0,y,n)
        {
            a[x][y] = buff[x][y]-'0';
            if(y)a[x][y]+=a[x][y-1];
            if(x)a[x][y]+=a[x-1][y];
            if(x&&y)a[x][y]-=a[x-1][y-1];
        }
        res = 0;
        fo(0,upx,n)fo(0,upy,n)
        	fo(upx,downx,n)fo(upy,downy,n)
			{
        		sum = a[downx][downy];
        		if(upx&&upy)sum+=a[upx-1][upy-1];
        		if(upx)sum-=a[upx-1][downy];
        		if(upy)sum-=a[downx][upy-1];
        		if((sum==(downy-upy+1)*(downx-upx+1))&&sum>res)
        			res = sum;
			}
        printf("%d\n",res);
        if(t)puts("");
    }
}

