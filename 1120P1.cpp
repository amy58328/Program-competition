#include<bits/stdc++.h>

using namespace std; 

vector<string>move;
vector<string>fin;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		getchar();
		
		move.clear();
		fin.clear();

		for(int i=0 ; i<n ; i++)
		{
			string temp;
			getline(cin, temp);
			move.push_back(temp);
		}

		for(int i=0 ; i<n ; i++)
		{
			string temp;
			getline(cin, temp);
			fin.push_back(temp);
		}

		while(!move.empty())
		{
			if(move.back() == fin.back())
			{
				move.pop_back();
				fin.pop_back();
			}
			else
			{
				move.pop_back();
			}
		}

		if(!fin.empty())
		{
			for(int i=fin.size()-1;i>=0 ; i--)
			{
				cout << fin[i] << endl;
			}
		}
		if(t !=0)
			cout << endl;

	}
	return 0;
}
