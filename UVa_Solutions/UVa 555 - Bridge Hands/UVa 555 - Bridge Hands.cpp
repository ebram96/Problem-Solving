// It's all about what U BELIEVE
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui long long
#define pb push_back
#define pop pop_back()
using namespace std;
int chk(char& c)
{
  if(c == 'C')return 0;
  else if(c == 'D') return 1;
  return (c == 'S' ? 2 : 3);
}
void sorti(int a[4][4][13] , int in0 , int in1 , int n)
{
	fo(y , n-1)
		for(int i = y+1 ; i < n ; i++)
			if(a[in0][in1][y] > a[in0][in1][i])
			{
				int sw = a[in0][in1][y];
				a[in0][in1][y] = a[in0][in1][i];
				a[in0][in1][i] = sw;
			}
}
void chk_card(char& c)
{
	if(c == 'T')
		c = 60;
	else if(c == 'J')
		c = 61;
	else if(c == 'Q')
		c = 62;
	else if(c == 'K')
		c = 63;
	else if(c == 'A')
		c = 64;
}
void print(char c , int a[4][4][13] , int leng , int n , int m)
{
	fo(y , leng)
	{
    	if(a[n][m][y] == 60) a[n][m][y] = 'T';
    	else if(a[n][m][y] == 61) a[n][m][y] = 'J';
    	else if(a[n][m][y] == 62) a[n][m][y] = 'Q';
    	else if(a[n][m][y] == 63) a[n][m][y] = 'K';
    	else if(a[n][m][y] == 64) a[n][m][y] = 'A';
    	printf(" %c%c" , c , a[n][m][y]);
	}
}
int main()
{
  char dealer;
  while(scanf("%c" , &dealer)&&dealer!='#')
  {
	short inde[4];
	switch (dealer)
	{
	case 'E':
	{
		inde[0] = 0;
		inde[1] = 1;
		inde[2] = 2;
		inde[3] = 3;
		break;
	}
	case 'S':
	{
		inde[0] = 3;
		inde[1] = 0;
		inde[2] = 1;
		inde[3] = 2;
		break;
	}
	case 'W':
	{
		inde[0] = 2;
		inde[1] = 3;
		inde[2] = 0;
		inde[3] = 1;
		break;
	}
	default :
	{
		inde[0] = 1;
		inde[1] = 2;
		inde[2] = 3;
		inde[3] = 0;
	}
	}
    // C < D < S < H
    int cnt[4][4] = {0} , cards[4][4][13] = {0} , ret , ind[4][4] = {0};
    char inp0 , inp1 ;
    fo(y , 13)
    {
      scanf("\n%c%c" , &inp0 , &inp1);
      ret = chk(inp0);
      cnt[0][ret]++;
      chk_card(inp1);
      cards[0][ret][ind[0][ret]] = inp1;
      ind[0][ret]++;
      scanf("%c%c" , &inp0 , &inp1);
      ret = chk(inp0);
      cnt[1][ret]++;
      chk_card(inp1);
      cards[1][ret][ind[1][ret]] = inp1;
      ind[1][ret]++;
      scanf("\n%c%c" , &inp0 , &inp1);
      ret = chk(inp0);
      cnt[2][ret]++;
      chk_card(inp1);
      cards[2][ret][ind[2][ret]] = inp1;
      ind[2][ret]++;
      scanf("%c%c" , &inp0 , &inp1);
      ret = chk(inp0);
      cnt[3][ret]++;
      chk_card(inp1);
      cards[3][ret][ind[3][ret]] = inp1;
      ind[3][ret]++;
    }
    fo(y , 4)
    	fo(i , 4)
			sorti(cards , y , i , cnt[y][i]);
    printf("%c:" , 'S');
    print('C' , cards , cnt[inde[0]][0] , inde[0] , 0);
    print('D' , cards , cnt[inde[0]][1] , inde[0] , 1);
    print('S' , cards , cnt[inde[0]][2] , inde[0] , 2);
    print('H' , cards , cnt[inde[0]][3] , inde[0] , 3);
    printf("\n");
    printf("%c:" , 'W');

    print('C' , cards , cnt[inde[1]][0] , inde[1] , 0);
    print('D' , cards , cnt[inde[1]][1] , inde[1] , 1);
    print('S' , cards , cnt[inde[1]][2] , inde[1] , 2);
    print('H' , cards , cnt[inde[1]][3] , inde[1] , 3);
    printf("\n");
    printf("%c:" , 'N');

    print('C' , cards , cnt[inde[2]][0] , inde[2] , 0);
    print('D' , cards , cnt[inde[2]][1] , inde[2] , 1);
    print('S' , cards , cnt[inde[2]][2] , inde[2] , 2);
    print('H' , cards , cnt[inde[2]][3] , inde[2] , 3);
    printf("\n");
    printf("%c:" , 'E');

    print('C' , cards , cnt[inde[3]][0] , inde[3] , 0);
    print('D' , cards , cnt[inde[3]][1] , inde[3] , 1);
    print('S' , cards , cnt[inde[3]][2] , inde[3] , 2);
    print('H' , cards , cnt[inde[3]][3] , inde[3] , 3);
    printf("\n");
    scanf("\n");
  }
}
 
