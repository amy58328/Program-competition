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
		int top[n];
		int floor[n];

		for(int i=0 ; i<n ; i++)
		{
			cin >> floor[i];
		}

		for(int i=0 ; i <n ; i++)
		{
			cin >> top[i];
		}

		int top_r[n];
		int top_l[n];

		int min = 2000;
		for(int i=0 ; i<n ; i++)
		{
			if(min > top[i])
			{
				min = top[i];
			}

			if(min < floor[i])
			{
				min = floor[i];
			}

			top_r[i] = min;
		}

		min = 2000;
		for(int i=n-1 ; i>=0 ; i--)
		{
			if(min > top[i])
			{
				min = top[i];
			}

			if(min < floor[i])
			{
				min = floor[i];
			}

			top_l[i] = min;

			if(top_l[i]<top_r[i])
			{
				top_r[i] = top_l[i];
			}
		}

		int ans = 0;
		for(int i=0 ; i<n ; i++)
		{
			if(top_r[i] > floor[i])
			{
				ans += top_r[i] - floor[i];
			}
		}

		cout << ans <<endl;
	}
	return 0;
}