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
#define llu unsigned long long
#define lld long long
using namespace std;
bool bina(char a , char b){return a < b;}
/*int int_c (const void * a, const void * b)
{
  if ( *(char*)a <  *(char*)b ) return -1;
  if ( *(char*)a == *(char*)b ) return 0;
  if ( *(char*)a >  *(char*)b ) return 1;
}*/
bool bin(char& a , char& b)
{
	bool ret = 0 , sw0 = 0 , sw1 = 0;
	if(a<='z'&&a>='a'){sw0 = 1;a-=32;}
	if(b<='z'&&b>='a'){sw1 = 1;b-=32;}
	if(a<b)ret = 1;
	if(sw0)a+=32;
	if(sw1)b+=32;
	return ret;
}
bool bin0(string& a , string& b)
{
	unsigned int len = a.length();
	bool ret = 0 ;
	fo(y , len)
	{
		bool sw0 = 0 , sw1 = 0;
		if(a[y] == b[y] + 32)
		{
			ret = 0;
			break;
		}
		else if(a[y]+32 == b[y])
		{
			ret = 1;
			break;
		}
		if(a[y]<='z'&&a[y]>='a'){sw0 = 1;a[y]-=32;}
		if(b[y]<='z'&&b[y]>='a'){sw1 = 1;b[y]-=32;}
		if(a[y] < b[y])
		{
			if(sw0)a[y]+=32;
			if(sw1)b[y]+=32;
			ret = 1;
			break;
		}
		else if(b[y] < a[y])
		{
			if(sw0)a[y]+=32;
			if(sw1)b[y]+=32;
			break;
		}
		if(sw0)a[y]+=32;
		if(sw1)b[y]+=32;
	}
	return ret;
}
int main()
{
	unsigned long n ;
	char s[200];
	scanf("%lu" , &n);
	while(n--)
	{
		vector<string> v;
		scanf("%s" , s);
		int len = strlen(s);
		sort(s , s+len , bina);
		v.pb(s);
		while(next_permutation(s , s+len))v.pb(s);
		sort(v.begin() , v.end() , bin0);
		fo(y , v.size())puts(v[y].c_str());
	}
}
