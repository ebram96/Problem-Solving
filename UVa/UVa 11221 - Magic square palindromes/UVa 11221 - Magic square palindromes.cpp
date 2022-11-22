//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<map>
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui unsigned int
#define ull unsigned long long
#define pb push_back
#define gcu getchar_unlocked
#define wtm while(t--)
using namespace std;
inline bool pal(char* s)
{
	ui len = strlen(s);
	fo(y , len)if(s[y] != s[len - y - 1])return 0;
	return 1;
}
inline bool mir(char* s)
{
	char t[21];
	strcpy(t , s);
	ui len = strlen(s);
	bool ret = 0 , f = 0;
	fo(y , len)
	{
		if(t[y] == '0')
			t[y] = 'O';
		else if(t[y] == 'E')
		{
			t[y] = '3';
			ret = 1;
		}
		else if(t[y] == 'J')
		{
			t[y] = 'L';
			ret = 1;
		}
		else if(t[y] == 'L')
		{
			t[y] = 'J';
			ret = 1;
		}
		else if(t[y] == 'Z')
		{
			t[y] = '5';
			ret = 1;
		}
		else if(t[y] == '2')
		{
			t[y] = 'S';
			ret = 1;
		}
		else if(t[y] == 'S')
		{
			t[y] = '2';
			ret = 1;
		}
		else if(t[y] == '5')
		{
			t[y] = 'Z';
			ret = 1;
		}
		else if(t[y] == '3')
		{
			t[y] = 'E';
			ret = 1;
		}
		else if(t[y] == 'A' ||t[y] == 'H' ||t[y] == 'I' ||t[y] == 'M' ||t[y] == 'O' ||t[y] == 'T' ||t[y] == 'U' ||t[y] == 'V' ||t[y] == 'W' ||t[y] == 'X' ||t[y] == 'Y' ||t[y] == '1' ||t[y] == '8')
			ret = 1;
		else f = 1;
	}
	if(f)ret = 0;
	reverse(t , t+len);
	if(!strcmp(s , t) && ret)
		return 1;
	else return 0;
}

int main()
{
	//freopen("/home/ebram96/Desktop/in" , "r" , stdin);freopen("/home/ebram96/Desktop/out" , "w" , stdout);
	char s[21];
	while(scanf("%s" , s) == 1)
	{
		printf("%s " , s);
		if(pal(s))
		{
			if(!mir(s))
				puts("-- is a regular palindrome.\n");
			else puts("-- is a mirrored palindrome.\n");
		}
		else
		{
			if(!mir(s))
				puts("-- is not a palindrome.\n");
			else puts("-- is a mirrored string.\n");
		}
	}
}
