#include<bits/stdc++.h>
#define N 105

using namespace std;

struct node
{
	int place;
	char status; //B,S,X=flood
};

node rock[N];
int n,l;

void readdata()
{
	rock[0].place = 0;
	rock[0].status = 'B';	
	for(int i=1 ; i<n+1 ; i++)
	{
		char a;
		int temp;
		cin >> a ;
		getchar();
		cin >> temp ;
		rock[i].place = temp;
		rock[i].status = a;	
	}
	rock[n+1].place = l;
	rock[n+1].status = 'B';
}

int findmax()
{
	//go
	int flag = 0; 
	int max = -1;
	int front = 0;
	for(int i=1 ; i<n+2 ;i++)
	{
		if(rock[i].status == 'B')
		{
			int temp = abs(rock[i].place - rock[front].place);
			if(temp > max)
			{
				max = temp;
			}
			front = i;
		}

		if(rock[i].status == 'S')
		{
			if(flag == 1)
			{
				flag = 0;
				int temp = abs(rock[i].place - rock[front].place);
				if(temp > max)
				{
					max = temp;
				}
				front = i;
				rock[i].status = 'X';
			}
			else
			{
				flag = 1;
			}
		}

	}

	//return 
	front = n+1;
	for(int i=n ; i>=0 ; i--)
	{
		if(rock[i].status != 'X')
		{
			int temp = abs(rock[i].place - rock[front].place);
			if(temp > max)
			{
				max = temp;
			}
			front = i;
		}
	}

	return max ;

}
int main()
{
	int t;
	cin >> t;
	for(int q=1 ; q<=t ; q++)
	{
		cin >> n >> l ;
		readdata();

		int max = findmax();
		printf("Case %d: %d\n",q,max );
	}	
	return 0 ;
}