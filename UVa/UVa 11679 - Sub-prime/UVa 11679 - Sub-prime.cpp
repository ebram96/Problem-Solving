/// It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<cmath>
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui int
#define pb push_back
using namespace std;
//bool bin(int a , int b){return a > b;}
int main()
{
    int n , b , d , c , val;
    long long credit[20];
    bool res;
    while(scanf("%d %d" , &b , &n))
    {
        if(!b&&!n)break;
        res = 1;
        fo(y , b)
            scanf("%lld" , &credit[y]);
        while(n--)
        {
            scanf("%d %d %d" , &d , &c , &val);
            credit[d-1]-=val;
            credit[c-1]+=val;
        }
        fo(y , b) if(credit[y]<0){res = 0; break;}
        (res ? printf("S\n") : printf("N\n"));
    }
}
