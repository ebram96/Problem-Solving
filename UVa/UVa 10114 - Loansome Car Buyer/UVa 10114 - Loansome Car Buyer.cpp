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
#define ui  long long
#define l length()
using namespace std;
int main()
{
	ui mon , monc , inpint;
	double price , down , loan , inpd , pay;
	vector<double> b;
	vector<ui> a;
	while(scanf("%lld %la %la %lld" , &mon , &down , &loan , &monc))
	{
		if(mon < 0)break;
		scanf("%lld %la" , &inpint , &inpd);
		price = loan + down;
		pay = loan / mon;
		a.push_back(inpint);
		b.push_back(inpd);
		monc--;
		while(monc--)
		{
			scanf("%lld %la" , &inpint , &inpd);
			a.push_back(inpint);
			b.push_back(inpd);
		}
		price -= (price * b[0]);
		for(ui y = 1 , ind = 1 ; ; y++)
		{
			if(loan < price)
			{
				if(y-1 == 1)
					cout<<y-1<<" month\n";
				else cout<<y-1<<" months\n";
				a.clear();
				b.clear();
				break;
			}
			else
			{
				if(ind < a.size())
				{
					if(y == a[ind])
					{
						price -= (price * b[ind]);
						ind++;
					}
					else price -= (price * b[ind-1]);
				}
				else price -= (price * b[ind-1]);
			}
			loan -= pay;
		}
	}
}

