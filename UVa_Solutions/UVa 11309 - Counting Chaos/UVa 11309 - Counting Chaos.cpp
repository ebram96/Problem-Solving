// It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<map>
#include<cstring>
#include<cmath>
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui unsigned int
#define pb push_back
using namespace std;
int qs(const void* a, const void* b)
{
	if(*(char*)a < *(char*)b)return -1;
	else if(*(char*)a == *(char*)b)return 0;
	else if(*(char*)a > *(char*)b)return 1;
}
bool pal(char* s)
{
	ui len = strlen(s);
	fo(y , len)if(s[y] != s[len - y - 1])return 0;
	return 1;
}
void to_str(ui n , char* dest)
{
	ui ind = 0;
	while(n)
	{
		dest[ind] = ((n%10)+48);
		n/=10;
		ind++;
	}
	dest[ind] = '\0';
}
int main()
{
	ui h , m , n;
	scanf("%u" , &n);
	char s[5];
	while(n--)
	{
		scanf("%u:%u" , &h , &m);
		while(1)
		{
			m++;
			if(m==60)
			{
				m = 0;
				h++;
				if(h==24)h=0;
			}
			h*=100;
			h+=m;
			to_str(h , s);
			if(pal(s))
			{
				h/=100;
				printf("%.2u:%.2u\n" , h , m);
				break;
			}
			h/=100;
		}
	}
}
