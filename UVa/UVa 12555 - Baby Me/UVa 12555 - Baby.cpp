//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define pb push_back
using namespace std;
int main ()
{
	int tc , c = 1;
	scanf("%d" , &tc);
	string a;
	while(tc--)
	{
		scanf("\n");
		getline(cin , a);
		if(a.length() == 4)
			printf("Case %d: %g\n" , c++ , (a[0]-'0')*0.5f);
		else if(a.length() == 5)
			printf("Case %d: 5\n" , c++);
		else if(a.length() == 8)
			printf("Case %d: %g\n" , c++ ,(a[0]-'0')*0.5f+(a[4]-'0')*0.05f);
		else
			printf("Case %d: %g\n" , c++ ,5.0f+(a[5]-'0')*0.05f);
	}
}
 
