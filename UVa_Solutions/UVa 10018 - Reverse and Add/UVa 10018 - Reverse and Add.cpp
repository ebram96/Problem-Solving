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
	fo(y , len/2)if(s[y] != s[len-y-1])return 0;
	return 1;
}
ui rev(ui n)
{
	ui ret = 0;
	while(n)
	{
		ret*=10;
		ret+=(n%10);
		n/=10;
	}
	return ret;
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
ui to_ui(char* s)
{
	ui ret = 0 , ten = 1 , len = strlen(s);
	fo(y , len)
	{
		ret+=((s[y]-'0')*ten);
		ten*=10;
	}
	return ret;
}
int main()
{
	ui t , n , res , com;
	scanf("%u" , &t);
	char t0[12];
	while(t--)
	{
		res = 0;
		scanf("%u" , &n);
		while(1)
		{
			res++;
			com = rev(n);
			to_str(com+n , t0);
			if(pal(t0))
			{
				printf("%u %s\n" , res , t0);
				break;
			}
			n = to_ui(t0);
		}
	}
}
 
