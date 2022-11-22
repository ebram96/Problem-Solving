//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<map>
#include<unordered_map>
//#include<bitset>
//#include<tuple>
#include<cmath>
//#include<cstdint>
#include<climits>
#include<set>
//#include<unordered_set>
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define ull unsigned long long
#define pb push_back
#define gcu getchar_unlocked
#define wtm while(t--)
#define non if(!n)break;
#define frop freopen("/home/ebram96/Desktop/in" , "r" , stdin);	freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
bool bin(string a , string b){return a > b;}
bool bina(int a , int b){return a > b;}
bool bin(ull a , ull b){return a > b;}
void rtat(char **a,int n)
{
	char **t = new char*[n];
	fo(y , n)t[y] = new char[n];
	fo(y , n)fo(i , n)t[y][i] = a[y][i];
	fo(y , n)fo(i , n)a[i][n-y-1] = t[y][i];
}
int find(char **a , char **b , int N , int n)
{
	int ret = 0 , cnt;
	for(int y = 0 ; y < N-n+1 ; y++)
	{
		for(int j = 0 ; j < N-n+1 ; j++)
		{
			cnt = 0;
			for(int yn = 0 ; yn < n ; yn++)
				for(int jn = 0 ; jn < n ; jn++)
					if(a[y+yn][j+jn] == b[yn][jn])cnt++;
					else jn = yn = n;//break;
			if(n*n == cnt)ret++;
		}
	}
	return ret;
}
int main()
{
	frop
	int n , N , r0 , r90 , r180 , r270;
	while(scanf("%d %d" , &N , &n))
	{
		non
		r0 &= r90 &= r180 &= r270 &= 0;
		char** a = new char*[N] , **b = new char*[n];
		fo(y , N)a[y] = new char[N];
		fo(y , n)b[y] = new char[n];
		gcu();
		fo(y , N)
		{
			fo(i , N)a[y][i] = gcu();
			gcu();
		}
		fo(y , n)
		{
			fo(i , n)b[y][i] = gcu();
			gcu();
		}
		r0 = find(a , b , N , n);
		rtat(b , n);
		r90 = find(a , b , N , n);
		rtat(b , n);
		r180 = find(a , b , N , n);
		rtat(b , n);
		r270 = find(a , b , N , n);
		printf("%d %d %d %d\n" , r0 , r90 , r180 , r270);
	}
}
