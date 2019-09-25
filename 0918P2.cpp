#include <bits/stdc++.h>
#define N 1000
#define loop(i,begin,n) for(int i=begin ;i<n;i++)

using namespace std ;
struct city
{
	int x;
	int y;
	int people;
};

struct data
{
	int from;
	int to;
	float cost;
};

city cities[N];
vector<data>vec;
int arr[N];
int num[N];

void init()
{
	loop(i,0,N)
	{
		arr[i] = i;
		num[i] = 1;
	}
}

bool rule(data a , data b)
{
	return a.cost < b.cost;
}

int find(int a)
{
	if(arr[a] == a)
		return a;
	else
	{
		arr[a] = find(a);
		return arr[a];
	}
}
int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif


	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >>n;
		loop(i,0,n)
		{
			int a,b,c;
			cin >> a>> b>> c;
			cities[i].x = a;
			cities[i].y = b;
			cities[i].people = c;
		}

		loop(i,0,n-1)
		{
			loop(j,0,n)
			{	
				if(i == j)
				{
					continue;
				}
				else
				{
					float temp = sqrt((cities[i].x - cities[j].x) * (cities[i].x - cities[j].x) + (cities[i].y - cities[j].y) * (cities[i].y - cities[j].y));
					vec.push_back((data){i,j,temp});	
				}
				
			}
		}

		sort(vec.begin() , vec.end() , rule);

		float mini_cost = 0;

		cout << "b"  ;
		cout << vec.size()<<endl;
		cout << "??";
		loop(j,0,vec.size())
		{
			cout << vec[j].from << " " << vec[j].to << " " << vec[j].cost << endl;
		}
		cout << "b"  ;
		cout << "a" ;

		loop(i,0,vec.size())
		{
			int from = vec[i].from;
			int to = vec[i].to;

			cout << from << " " << to;

			from = find(from);
			to = find(to);

			if(from != to)
			{
				if(num[from] > num[to])
				{
					num[from] ++;
					arr[to] = from;
				}
				else
				{
					num[to] ++;
					arr[from] = to;
				}

				mini_cost += vec[i].cost;
				cout << vec[i].cost<< " " ;
			}

		}

		cout << mini_cost;


	}	
	return 0;
}