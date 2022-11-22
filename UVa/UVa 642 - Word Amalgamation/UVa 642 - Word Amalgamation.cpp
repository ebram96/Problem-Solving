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
int main()
{
	char a[100][7] , b[100][7] , str[7];
	ui c = 0;
	bool found;
	vector<string>res;
	while(scanf("%s" , a[c]))
	{
		if(a[c][0] == 'X')break;
		strcpy(b[c] , a[c]);
		qsort(a[c] , strlen(a[c]) , sizeof(char) , qs);
		c++;
	}
	while(scanf("%s" , str))
	{
		found = 0;
		if(str[0] == 'X')
			break;
		qsort(str , strlen(str) , sizeof(char) , qs);
		fo(y , c)
			if(!strcmp(str , a[y]))
			{
				res.pb(b[y]);
				found=1;
			}
		if(!found)res.pb("NOT A VALID WORD");
		sort(res.begin() , res.end());
		unsigned int sz = res.size();
		fo(y , sz)printf("%s\n" , res[y].c_str());
		puts("******");
		res.clear();
	}

}
