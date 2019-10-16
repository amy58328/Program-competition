#include<bits/stdc++.h>
#define N 1000006

int num[N];
long long pointer[N];

using namespace std;

void init()
{
	for(int i=0 ; i<N ; i++)
	{
		pointer[i] = 0;
	}
}

int main()
{	
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	num[0] = 0;
	num[1] = 1;
	num[2] = 2;
	num[3] = 3;

	int t;
	cin >> t;
	for(int q=1 ; q<=t ; q++)
	{
		init();
		long long n;
		int m,k;
		cin >>n>>m>>k;
		int time = 0;
		bool all = false;
		
		long long  ans = 1000000;
		for(long long  i=1 ; i<=n ; i++)
		{
			if(i>3)
			{
				num[i]= ((num[i-1]+num[i-2] +num[i-3] )% m) +1;
			}
			

			if(num[i] <= k)
			{
				if(time <k)
				{
					if(pointer[num[i]] == 0)
					{
						pointer[num[i]] = i;
						time ++;	
					}

					else
						pointer[num[i]] = i;
				}

				if(time >=k)
				{
					pointer[num[i]] = i;
					all = true;
					long long min = 1000000,max = -1;
					for(int i=1 ; i<=k ; i++)
					{
						if(pointer[i] < min)
							min = pointer[i];
						if(pointer[i] > max)
							max = pointer[i];
					}
					long long temp = max - min+1;

					if(temp < ans)
						ans = temp;
				}
			}	
		}

		
		

		

		if(all)
			printf("Case %d: %lld\n",q,ans );
		else 
			printf("Case %d: sequence nai\n",q );
	}
}