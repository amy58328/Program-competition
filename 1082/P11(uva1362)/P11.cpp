#include<bits/stdc++.h>
#define N 300+10

using namespace std;

char s[N];
int d[N][N];

int dp(int i,int j)
{
	if(i == j) return 1;
	if(s[i] != s[j])return 0;

	if(d[i][j] != -1)
		return d[i][j];

	d[i][j] = 0;
	for(int k=i+2;k<=j;k++)
		if(s[i] == s[k])
			d[i][j] = (d[i][j] + (long long)dp(i+1,k-1)*(long long)dp(k,j))%1000000000;

	return d[i][j]; 


}

int main()
{
	while(scanf("%s",s) == 1)
	{
		
		memset(d,-1,sizeof(d));
		int ans = dp(0,strlen(s)-1);
		cout << ans << endl;
	}
}