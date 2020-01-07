#include<bits/stdc++.h>
#define N 1500

using namespace std;

vector<int>node[N+5];
int visite[N+5];
int dp[N+5][2];


void init()
{
	memset(node, 0, sizeof(node));	
	for(int i=0 ; i<N ; i++)
	{
		visite[i] = 0;
		dp[i][0] = 0;
		dp[i][1] = 1;
	}
}

void dfs(int a)
{
	visite[a] = 1;

	for(int i=0 ; i<node[a].size() ; i++)
	{
		int v = node[a][i];

		if(visite[v] == 1)
			continue;

		dfs(v);

		dp[a][0] += dp[v][1];
		dp[a][1] += min(dp[v][0], dp[v][1]);
	}
}


int solve(int n)
{
	int ans = 0;

	for(int i=0 ; i<n ; i++)
	{
		if(visite[i])
			continue;
		dfs(i);

		ans += min(dp[i][0],dp[i][1]);
	}
	return ans ;
}

int main()
{
	int n;
	while(cin >> n)
	{

		init();
		int a,b;
		for(int j=0 ; j<n ; j++)
		{
			scanf("%d%*c%*c%d%*c",&a,&b);
		
			for(int i=0 ; i<b ; i++)
			{
				int temp;
				cin >> temp;

				node[a].push_back(temp);
				node[temp].push_back(a);
			}
		}

		int ans = solve(n);

		cout << ans << endl;
	}
}