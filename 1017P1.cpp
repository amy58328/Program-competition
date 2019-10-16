#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int num[n];
		int time[n];

		for(int i=0 ; i<n ; i++)
		{
			time[i] = 0;
		}

		for(int i=0 ; i<n ; i++)
		{
			cin >> num[i];
		}

		int temp = 0;
		for(int i=0 ; i<n ; i++)
		{
			for(int j=i+1 ; j<n ; j++)
			{
				if(num[i] > num[j])
				{
					time[i]++;
				}
			}

			temp += time[i];
		}

		if(n % 2 == 1 && temp % 2 == 1)
		{
			printf("impossible\n");
		}

		else
		{
			printf("possible\n");
		}
	}
	return 0;
}