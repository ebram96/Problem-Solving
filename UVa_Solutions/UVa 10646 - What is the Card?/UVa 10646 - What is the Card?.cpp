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
	vector<char* > cards;
	char inp[52][3];
    unsigned int n , c = 1;
    scanf("%u\n" , &n);
    while(n--)
    {
        unsigned int ind = 26 , y = 0 , x;
        fo(z , 52)
        {
            scanf("%s" , inp[z]);
            cards.pb(inp[z]);
        }
        fo(z , 3)
        {
            if(cards[ind][0] <= '9')
            x = (cards[ind][0]-'0');
            else x=10;
            y+=x;
            cards.erase(cards.begin()+ind-(10-x)-1 ,cards.begin()+ind);
            ind-=(10-x);
        }
        printf("Case %u: %s\n" , c++ , cards[y-1]);
        cards.clear();
    }
}
 
