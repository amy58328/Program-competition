#include <bits/stdc++.h>

using namespace std;

int queens[100][8];
int total = 0;
int temp[8] = {0};
int row[8] = {0},Right[15] = {0}, Left[15] = {0};
int weight[8][8];



void Queens(int c)
{
	if(c == 8)
	{
		for(int i = 0 ; i< 8 ; i++)
		{
			queens[total][i] = temp[i];
		}

		total ++; 
		return ;
	}

	for(int i = 0 ; i< 8 ; i++)
	{
		int r = c-i+7;
		int l = c+i;
		if(Right[r] == 0 && Left[l] == 0 && row[i] == 0)
		{
			Right[r] = 1;
			Left[l] = 1;
			row[i] = 1;

			temp[c] = i;

			Queens(c+1);

			Right[r] = 0;
			Left[l] = 0;
			row[i] = 0;
		}
	}
}

int main()
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	Queens(0);
	
	int t;
	cin >> t;
	while(t--)
	{

		for(int i=0 ; i<8 ; i++)
		{
			for(int j=0 ; j<8 ; j++)
				cin >> weight[i][j];
		}


		int max = 0;
		int ans = 0;
		for(int i=0 ; i<total ; i++)
		{
			for(int j=0 ; j<8 ; j++)
			{
				int r = queens[i][j];

				ans += weight[j][r];

			}

			if(max < ans)
				max = ans ;
			ans = 0;
		}
		
		cout << max << endl;

	}

	
	return 0 ;

}