#include<bits/stdc++.h>

using namespace std ;

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
		int a,b,c;
		cin >> a>>b>>c;
		vector<int>ans;
		int place = 0;
		ans.push_back(place);

		if(c % 3 == 0)
		{
			int temp = c/3;
			for(int i=0 ; i < temp ; i++)
			{
				place += 3;
				ans.push_back(place);
			}

			a -=1;
			place += 1;
			ans.push_back(place);

			for(int i=0 ; i<temp ; i++)
			{
				place-= 3;
				ans.push_back(place);
			}

			a-=1;
			place+=1;
			ans.push_back(place);

			for(int i=0 ; i<temp ; i++)
			{
				place += 3;
				ans.push_back(place);	
			}

		}

		else if(c% 3 == 1)
		{
			int temp = c/3;

			for(int i=0 ; i <= temp ; i++)
			{
				place += 3;
				ans.push_back(place);
			}

			b  -=1;
			place -= 2;
			ans.push_back(place);

			for(int i=0 ; i<temp ; i++)
			{
				place-= 3;
				ans.push_back(place);
			}

			a-=1;
			place+=1;
			ans.push_back(place);

			for(int i=0 ; i<temp ; i++)
			{
				place += 3;
				ans.push_back(place);	
			}

			b-=1;
			place += 2;
			ans.push_back(place);
		}

		else
		{
			int temp = c/3;
			for(int i=0 ; i <= temp ; i++)
			{
				place += 3;
				ans.push_back(place);
			}

			a -=1;
			place -= 1;
			ans.push_back(place);

			for(int i=0 ; i<temp ; i++)
			{
				place-= 3;
				ans.push_back(place);
			}

			a-=1;
			place-=1;
			ans.push_back(place);

			for(int i=0 ; i<=temp ; i++)
			{
				place += 3;
				ans.push_back(place);	
			}

		}

		while(a>1)
		{
			place += 1;
			a-=1;
			ans.push_back(place);
		}

		for(int i=0 ; i<(b+1)/2 ; i++)
		{
			place +=2 ;
			ans.push_back(place);
		}

		if(b % 2 !=0)
		{
			place -= 1;
			ans.push_back(place);	
		}
		else
		{
			place += 1;
			ans.push_back(place);
		}
		
		for(int i=0 ; i<b/2 ; i++)
		{
			place -= 2;
			ans.push_back(place);
		}

		for(int i=0 ; i<ans.size() ; i++)
		{
			cout << ans[i] <<" ";
		}
		cout << endl;
	}
	return 0;
}

// 先看C
// 如果C% 3 == 0
// 往右C/3次三格 往右一格 往左C/3次三格 往右一格 往右C/3次三格

// 如果C%3 == 1
// 往右C/3+1次三格 往左兩格 往左C/3次三格 往右一格 往右C/3次三格 往右兩格

// 如果C%3==2
// 往右C/3+1次三格 往左一格 往左C/3次三格 往左一格 往右C/3+1次三格

// 往右a-1格

// 往右( b+1)/2格

// 如果b是基數
// 	往左一格

// 如果b是偶數
// 	往右一格

// 往左b/2格


