#include<bits/stdc++.h>
#define N 16384

using namespace std;


int player[N+5][3];
int com[7];
int Rank[N+5];

void find(int index,int a,int b ,int c)
{
	com[0] = a;
	com[1] =b;
	com[2] = c;
	com[3] = a +b;
	com[4] = a + c;
	com[5] =b + c;
	com[6] = a +b + c;

	sort(com,com+7);
}
int main(int argc, char const *argv[])
{
	int n;
	int t = 1;

	while(cin >> n && n)
	{
		int player[n][3];
		int Rank[n];

		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ;j<3 ; j++)
			{
				double temp ;
				cin >> temp;
				player[i][j] = round(temp * 100);
			}
		}

		for(int i=0 ; i<n ; i++)
		{
			int a;
			cin >> a;
			Rank[i] = a-1;
		}

		int ans = player[Rank[0]][0] + player[Rank[0]][1] + player[Rank[0]][2] ;

		for(int i=1 ; i<n ; i++)
		{
			int num = Rank[i];
			int num1 = Rank[i-1];
			int total = player[num][0] + player[num][1] + player[num][2];
			find(num, player[num][0], player[num][1], player[num][2]);
			int index = 0;

			if(num > num1 )
			{
				while(ans < total && index < 7)
				{
					total = player[num][0] + player[num][1] + player[num][2];
					total -= com[index++];
				}
			}

			else if(num < num1)
			{
				while(ans <= total && index < 7)
				{
					total = player[num][0] + player[num][1] + player[num][2];
					total -= com[index++];
				}
			}

			ans = total;
			
		}

		if(ans > 0)
			printf("Case %d: %.2f\n",t++,ans/100.0);
		else
			printf("Case %d: No solution\n",t++);
	}
	return 0;
}