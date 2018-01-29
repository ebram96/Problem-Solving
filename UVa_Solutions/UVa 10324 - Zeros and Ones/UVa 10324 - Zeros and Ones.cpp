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
    char s[1000001];
    unsigned int n , x , y , c = 1;
    bool res;
    while(scanf("%s" , s) == 1)
    {
        printf("Case %u:\n" , c++);
        scanf("%u" , &n);
        while(n--)
        {
            scanf("%u %u" , &x , &y);
            if(x > y)
            {
                unsigned int sw = x;
                x = y;
                y = sw;
            }
            char ch = s[x];
            x++;
            for(; x <= y ; x++)
                if(s[x]!=ch)
                {
                    printf("No\n");
                    break;
                }
            if(x>y)printf("Yes\n");
        }
    }
}
 
