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
#define ui unsigned int
#define pb push_back
using namespace std;
//bool bin(int a , int b){return a > b;}
int main()
{
    int t , cas=1;
    scanf("%d\n" , &t);
    char s[100001];
    while(t--)
    {
        unsigned char a[100] = {0} , ptr = 0;
        scanf("%s" , s);
        fo(y , strlen(s))
        {
            if(s[y] == '>')
            {
                ptr++;
                if(ptr>=100)ptr=0;
            }
            else if(s[y] == '<')
            {
                ptr--;
                if(ptr==255)ptr=99;
            }
            else if(s[y] == '+')
                a[ptr]++;
            else if(s[y] == '-')
                a[ptr]--;
        }
        printf("Case %d:" , cas++);
        fo(y , 100)
            printf(" %.02X" , a[y]);
        printf("\n");
    }
}
