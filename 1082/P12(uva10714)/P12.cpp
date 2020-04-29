#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int l,n;
		cin >> l >> n;
		int ant[n];
		int mi = l/2;
		int mini = -1;
		int max;

		for(int i=0 ; i<n ; i++)
		{
			cin >> ant[i];
			if(ant[i]<=mi)
			{
				if(ant[i] > mini)
					mini = ant[i];
			}

			else
			{
				int temp = l - ant[i];
				if(temp > mini)
						mini = temp;
			}
		}

		cout << mini <<" ";

		sort(ant,ant+n);
		max = l - ant[0];

		if(ant[n-1] > max)
			max = ant[n-1];

		cout << max << endl;



	}
}