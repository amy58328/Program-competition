#include<bits/stdc++.h>
#define N 1130

using namespace std;

int dp[N][15] = {0};
int prime[N] = {1};

void Prime()
{
	prime[0] = 0;
	prime[1] = 0;

	for(int i=2; i<=N ; i++)
	{
		if(prime[i] == 1)
		{
			for(int j=i+i ; j<=N ; j+=i)
			{
				prime[j] = 0;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	Prime();
	int n,k;
	while(cin >>n >> k)
	{
		if((n+k) == 0)
			break;

	}	
	return 0;
}