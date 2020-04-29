#include<bits/stdc++.h>

using namespace std;

long long next(int n,long long k)
{
	stringstream ss;
	ss << (long long )k;
	string s ;
	ss >> s;
	s = s.substr(0,n);

	int ans ;

	stringstream sss;
	sss.str(s);
	sss >> ans;
	return ans; 
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		long long k;
		cin >> n >> k;
		set<long long>s;
		long long ans = -1;
		while(!s.count(k))
		{
			s.insert(k);
			ans = max(ans,k);
			k = next(n,k*k);
		}

		cout << ans << endl;
	}
}