#include<bits/stdc++.h>

using namespace std;


int n[7];
int onenum[4] = {0,7,6,5};
int twonum[4] = {0,5,3,1};

int main()
{
	while(1)
	{
		int temp = 0;
		for(int i=1 ; i<7 ; i++)
		{
			cin >> n[i] ;
			temp += n[i];
		}

		if(temp == 0)
			break;

		int ans = n[6] + n[5] + n[4] + n[3]/4;
		// printf("ans = %d\n",ans );

		if(n[3] % 4 != 0)
			ans++;

		int one,two;

		one = 11*n[5] + onenum[n[3]%4];
		two = 5*n[4] + twonum[n[3]%4];


		// printf("one = %d two = %d\n",one ,two );

		if(n[2] > two)
		{
			int leave = n[2] - two;
			if(leave% 9 != 0)
			{
				ans += leave/9+1;
				one += (9-leave%9)*4;

			}

			else
			{
				ans += leave/9;
			}
		}

		else
		{
			one += (two - n[2])*4;
		}

		if(n[1] > one)
		{
			ans += (n[1] - one)/36+1;
		}

		cout << ans << endl;



	}
}