#include<bits/stdc++.h>
#define N 200000

using namespace std;

int num[N+10];
int FT[N+10];

void init()
{
	memset(FT,0,sizeof(FT));
}

int main()
{
	int t;
	while(cin >> t)
	{
		init();
		if(t == 0)
			break;

		for(int i=1 ; i<=t ; i++)
		{
			cin >> num[i];
			int j=i;

			while(j<=t)
			{
				FT[j] += num[i];
				j += (j & -j);
			}
		}

		char act ;
		while(cin >> act)
		{
			if(act == 'E')
			{
				getchar();
				getchar();
				break;
			}

			else if(act == 'M')
			{
				int from ,to;
				cin >> from >> to;
				from -= 1;
				int temp =0; 
				while(to > 0)
				{
					temp += FT[to];
					to -= (to & -to);
				}

				while(from > 0 )
				{
					temp -= FT[from];
					from -= (from & -from);
				}

				cout << temp << endl;
			}

			else if(act == 'S')
			{
				int index, change;
				cin >> index >> change;
				int temp = num[index];
				num[index] = change;
				change -= temp;

				while(index <= t)
				{
					FT[index] += change;
					index += (index & -index);
				}
			}
		}

	}

	return 0;

}