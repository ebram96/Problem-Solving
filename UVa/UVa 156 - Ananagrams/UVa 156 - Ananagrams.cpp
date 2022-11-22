// It's all about what U BELIEVE
#include<stdio.h>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cstring>
#include<iostream>
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui unsigned int
#define pb push_back
#define llu unsigned long long
#define lld long long
using namespace std;
bool strc(char* a , char* b)
{
	return (strcmp(a , b) < 0);
}
int qs(const void* a ,const void* b)
{
	if(*(char*) a > *(char*) b)return -1;
	if(*(char*) a == *(char*) b)return -1;
	if(*(char*) a < *(char*) b)return -1;
}
int main()
{
	char a[20000][21] , b[20000][21];
	unordered_map<string , int> m;
	vector<char*> res;
	unsigned int c = 0 , len;
	while(scanf("%s" , a[c]))
	{
		if(a[c][0]=='#')
		{
			unordered_map<string , int>::iterator en = m.end();
			unordered_map<string , int>::iterator be = m.begin();
			while(be!=en)
			{
				if((*be).second != -1)
					res.pb(a[(*be).second]);
				be++;
			}
			sort(res.begin() , res.end() , strc);
			unsigned int sz = res.size();
			fo(y , sz)puts(res[y]);
			return 0;
		}
		else
		{
			len = strlen(a[c]);
			strcpy(b[c] , a[c]);
			fo(y , len)if(b[c][y]>'Z')b[c][y]-=32;
			sort(b[c] , b[c]+len);
			unordered_map<string , int>::iterator ret = m.find(b[c]);
			if(ret!=m.end())(*ret).second = -1;
			else m.insert(pair<string , int> (b[c] , c));
		}
		c++;
	}
}
