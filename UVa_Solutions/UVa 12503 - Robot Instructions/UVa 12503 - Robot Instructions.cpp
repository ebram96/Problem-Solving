// It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<sstream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<cmath>
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui long long
#define l length()
using namespace std;
int main()
{
	ui t , n , res ;
	vector<ui> a;
	string s , ts;
	cin>>t;
	while(t--)
	{
		cin>>n;
		res = 0;
		cin.ignore();
		while(n--)
		{
			getline(cin , s);
			if(s[s.length()-2] == 'H')
			{
				res++;
				a.push_back(1);
			}
			else if(s[s.length()-2] == 'F')
			{
				res--;
				a.push_back(0);
			}
			else
			{
				ts = s.substr(8 , 2);
				if(a[atoi(ts.c_str())-1] == 1)
				{
					res++;
					a.push_back(1);
				}
				else
				{
					res--;
					a.push_back(0);
				}
			}
		}
		cout<<res<<endl;
		a.clear();
	}
}

