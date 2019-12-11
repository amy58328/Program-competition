#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		int arr[n];
		for(int i=0 ; i<n ; i++)
		{
			cin >> arr[i] ;
		}

		int tar;
		cin >> tar ;
		int ans[2];
		int aa = 10000;

		sort(arr,arr+n);

		for(int i=0 ; i<n-1 ; i++)
		{
			for(int j=i+1 ; j<n ; j++)
			{
				if(arr[i] + arr[j] == tar && abs(arr[i] - arr[j]) < aa)
				{
					aa = abs(arr[i] - arr[j]);
					ans[0] = arr[i] ;
					ans[1] = arr[j];
				}
			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", ans[0] , ans[1] );
	}
	
}