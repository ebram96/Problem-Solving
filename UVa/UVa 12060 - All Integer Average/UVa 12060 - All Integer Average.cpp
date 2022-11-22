// It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<cmath>
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui long long
using namespace std;
int main()
{
    int n , inp , b , c, wid , wid_ave , ave , cas=1;
    bool neg ;
    while(scanf("%d" , &n))
    {
        if(!n)break;
        wid = b = wid_ave = neg = 0;
        c = n;
        while(n--)
        {
            scanf(" %d", &inp);
            b+=inp;
        }
        printf("Case %d:\n" , cas++);
        if(b<0)
        {
            wid = 2;
            b*=(-1);
            neg = 1;
        }
        if(!(b%c))
        {
            if(neg) printf("- %d\n" , b/c);
            else printf("%d\n" , b/c);
            continue;
        }
        ave = b / c;
        int gc = __gcd(b , c) , t;
        b = b/gc;
        c = c/gc;
        if(b > 1)
        {
            if(b > c)b = b%c;
            else c = c%b;
        }
        t = c;
        while(t)
        {
            wid++;
            t/=10;
        }
        t = ave;
        while(t)
        {
            wid_ave++;
            t/=10;
        }
        if(neg)
        {
            cout<<setw(wid+wid_ave)<<b;
            if(ave) printf("\n- %d" , ave);
            else printf("\n- ");
            for(int y = 0 ; y < wid-2 ; y++)printf("-");
            printf("\n");
            cout<<setw(wid+wid_ave)<<c<<endl;
        }
        else
        {
            cout<<setw(wid+wid_ave)<<b;
            if(ave) printf("\n%d" , ave);
            else printf("\n");
            for(int y = 0 ; y < wid ; y++)printf("-");
            printf("\n");
            cout<<setw(wid+wid_ave)<<c<<endl;
        }
    }
}

