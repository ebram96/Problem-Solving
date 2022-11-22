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
	ui t , m , f;
	string s;
	scanf("%lld\n" , &t);
	while(t--)
	{
		f = m = 0;
		getline(cin , s);
		fo(y , s.length())
		{
			if(s[y] == 'M')m++;
			else if(s[y] == 'F')f++;
		}
		if(m == f && f>1)printf("LOOP\n");
		else printf("NO LOOP\n");
	}
}

