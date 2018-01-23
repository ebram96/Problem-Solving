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
	char inp[21];
	bool first = 1;
	while(scanf("\n%s",inp)!=EOF)
	{
		int a[3]={0} , ind = 0 , pre = 0;
		if(inp[0]=='B'||inp[0]=='P'||inp[0]=='V'||inp[0]=='F')
			pre = 1;
		else if(inp[0] == 'C'||inp[0] == 'S'||inp[0] == 'K'||inp[0] == 'G'||inp[0] == 'J'||inp[0] == 'Q'||inp[0] == 'X'||inp[0] == 'Z')
			pre = 2;
		else if(inp[0] == 'D' || inp[0] == 'T')
			pre = 3;
		else if(inp[0] == 'L')
			pre = 4;
		else if(inp[0] == 'N' || inp[0] == 'M')
			pre = 5;
		else if(inp[0] == 'R')
			pre = 6;
		for(unsigned int i=1;i<strlen(inp);i++){
			if(ind >= 3)break;
			if((inp[i]=='B'||inp[i]=='P'||inp[i]=='V'||inp[i]=='F'))
			{
				if(pre == 1)continue;
				a[ind] = 1;
				ind++;
				pre = 1;
			}
			else if((inp[i] == 'C'||inp[i] == 'S'||inp[i] == 'K'||inp[i] == 'G'||inp[i] == 'J'||inp[i] == 'Q'||inp[i] == 'X'||inp[i] == 'Z'))
			{
				if(pre == 2)continue;
				a[ind] = 2;
				ind++;
				pre = 2;
			}
			else if((inp[i] == 'D' || inp[i] == 'T'))
			{
				if(pre == 3)continue;
				a[ind] = 3;
				ind++;
				pre = 3;
			}
			else if(inp[i] == 'L' )
			{
				if(pre == 4)continue;
				a[ind] = 4;
				ind++;
				pre = 4;
			}
			else if((inp[i] == 'N' || inp[i] == 'M'))
			{
				if(pre == 5)continue;
				a[ind] = 5;
				ind++;
				pre = 5;
			}
			else if(inp[i] == 'R')
			{
				if(pre == 6)continue;
				a[ind] = 6;
				ind++;
				pre = 6;
			}
			else pre = 0;
		}
		if(first)
		printf("         NAME                     SOUNDEX CODE\n");
		first = 0;
		for(int sp = 1 ; sp <= 35 ; sp++)
		{
			if(sp==10)
			{
				printf("%s" , inp);
				sp+=strlen(inp)-1;
			}
			else if(sp == 35)
				printf("%c%d%d%d\n" , inp[0] , a[0] , a[1] , a[2]);
			else printf(" ");
		}
	}
	printf("                   END OF OUTPUT\n");
}
 
