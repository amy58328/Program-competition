#include<bits/stdc++.h>
#define N 1130

using namespace std;

int dp[N][15];
int prime[N] ;
int prime_number[N];

void init()
{	
	int index = 0;
	for(int i=0 ; i<=N ; i++)
	{
		prime[i] = 1 ;
	}

	prime[0] = 0;
	prime[1] = 0;

	for(int i=2; i<=N ; i++)
	{
		if(prime[i] == 1)
		{	
			prime_number[index++] = i;			

			for(int j=i+i ; j<=N ; j+=i)
			{
				prime[j] = 0;
			}
		}
	}

	dp[0][0] = 1;

	for(int i=0 ; i<index ;i++)
	{
		for(int j = N ; j>=prime_number[i] ; j--)
		{
			for(int k=1;k<=14;k++)
			{
				dp[j][k] += dp[j-prime_number[i]][k-1];
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	init();
	int n,k;
	while(cin >>n >> k)
	{
		if((n+k) == 0)
			break;
		cout << dp[n][k]<<endl;
	}	
	return 0;
}