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
vector<int>path;
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
		arr[a] = find(arr[a]);
		return arr[a];
	}
}

float mini_span_tree(float mini_cost)
{	
	loop(i,0,vec.size())
		{
			cout<< "i = " <<  i <<endl;

			cout << vec[i].from << " " << vec[i].to << endl;
			int f = vec[i].from;
			int t = vec[i].to;

			f = find(f);
			t = find(t);

			if(f != t)
			{
				if(num[f] > num[t])
				{
					num[f] ++;
					arr[t] = f;
				}
				else
				{
					num[t] ++;
					arr[f] = t;
				}
				mini_cost += vec[i].cost;


			}

		}
	return mini_cost;
}

void serial(int n)
{
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
		init();
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

		serial(n);

		sort(vec.begin() , vec.end() , rule);

		float mini_cost = 0;
		mini_cost = mini_span_tree(mini_cost);

		cout << mini_cost;

		loop(i,0,path.size())
		{
			cout << path[i] << " " ;
		}




	}	
	return 0;
}