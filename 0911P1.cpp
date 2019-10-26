#include<bits/stdc++.h>
#define N 33001

using namespace std;

int prime[N];
int use[N];

void Prime()
{
	prime[0] = 0;
	prime[1] = 0;
	for(int i=2 ; i<=N ; i++)
	{
		prime[i] = 1;
	}

	for(int i=2; i<=N ; i++)
	{
		if(prime[i] == 1)
		{
			for(int j=i+i ;j<=N ; j=j+i )
			{
				prime[j] = 0;
			}
		}
	}
}
void init()
{
	for(int i=0 ; i<N ; i++)
	{
		use[i] = 0;
	}
}

int findans(long long a )
{
	int ans = 0;
	for(int i=0 ; i<=a/2;i++)
	{
		if(prime[i] == 1 && use[i] != 1)
		{
			int temp = a - i;
			if(prime[temp] == 1 && use[temp] != 1)
			{
				ans++;
				use[i] = 1;
				use[temp] = 1;
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	Prime();
	long long num;
	while(cin >> num)
	{
		if(num == 0 )
			break;
		init();
		int ans ;
		ans = findans(num);

		cout << ans<<endl;
	}
	return 0;
}