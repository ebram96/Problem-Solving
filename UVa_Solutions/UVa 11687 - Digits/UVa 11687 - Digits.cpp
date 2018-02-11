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
    char s[1000001];
    ui i , c;
    while(scanf("%s" , s))
    {
        if(isalpha(s[0]))break;
        c = 0;
        for(long long y = strlen(s)-1 , ten = 1 ; y>=0 ; y-- , ten*=10)
        	c+=(s[y]-'0')*ten;
        i = strlen(s);
        for(ui y = 1 ; ; y++)
        {
            if(i==c){printf("%d\n" , y);break;}
            c = i;
            ui temp = i;
            i = 0;
            while(temp)
            {
                i++;
                temp/=10;
            }
        }
    }
}
