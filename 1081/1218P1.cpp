#include<bits/stdc++.h>
#define N 100000
using namespace std;

struct node {
	int from,to,cost;
};

node road[N];
int dis[N];
vector<int int>path[N];

void init()
{
	for(int i=0 ;i<N ;i++)
	{
		dis[i] = -1;
	}
}

bool rule(node a, node b)
{
	return a.cost < b.cost;
}

int find(int index)
{
	if(dis[index] > 0)
	{
		dis[index] = find(dis[index]);
		return dis[index];
	}
	else
		return index;
}

int main()
{
	int n,m;
	cin >> n>> m;

	for(int i=0 ; i<m ; i++)
	{
		int a,b,c;
		cin >>a >>b >> c ;
		road[i].from = a;
		road[i].to = b;
		road[i].cost = c;
	}

	sort(road,road+m,rule);

	for(int i=0 ; i<m ; i++)
	{
		int from = road[i].from;
		int to = road[i].to;

		from = find(from);
		to = find(to);

		if(from != to) // not the same set
		{
			if(dis[from] < dis[to]) // from's set > to's set
			{
				dis[from] += dis[to];
				dis[to] = from;
			}

			else if(dis[from] > dis[to]) // from's set < to's set
			{
				dis[to] += dis[from];
				dis[from] = to;
			}


		}
	}
}
