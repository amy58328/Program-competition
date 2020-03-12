//uva 1594

#include<bits/stdc++.h>
#define loop(i,n) for(int i=0 ;i<n;i++)
using namespace std;

int main(int argc, char* argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int t ;
	cin >>t; 
	while(t--)
	{
		int n;
		cin >> n ; 
		int num[n];
		loop(i,n)
			cin >>num[i];

		bool zero = 1;
		loop(q,1000)
		{
			int temp = num[0];
			int time = 0 ;
			loop(i,n)
			{
				if(i == n-1)
				{
					num[i] = abs(num[i] - temp);
					if(num[i] == 0)
						time++;

				}

				else
				{
					num[i] = abs(num[i] - num[i+1]);
					if(num[i] == 0)
						time++;
				}

				
			}

			if(time == n)
			{
				zero = 0;
				cout << "ZERO" <<endl;
				break;
			}
		}

		if(zero)
			cout << "LOOP" <<endl;
	}

	return 0;
}