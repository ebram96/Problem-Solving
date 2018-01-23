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
	string s;
	while(getline(cin , s))
	{
		int a[123] = {0} , max = 0;
		vector<int> res;
		for(int y = 0 ; y < s.length() ; y++)
		{
			if(isalpha(s[y]))
			{
				a[s[y]]++;
				if(a[s[y]] > max)
				{
					max = a[s[y]];
					res.clear();
					res.push_back(s[y]);
				}
				else if(a[s[y]] == max)
					res.push_back(s[y]);
			}
		}
		sort(res.begin() , res.end());
		for(int y = 0 ; y < res.size() ; y++)
			printf("%c" , res[y]);
		printf(" %d\n" , max);
	}
}
