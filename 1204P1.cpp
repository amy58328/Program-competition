#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
	if(a % b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b , a%b);
	}
}

int main()
{
	string input ;

	while(1)
	{
		getline(cin,input);
		if(input.size() == 1)
			break;

		int num = 0;
		for(int i=2 ; i<=input.size()-4 ; i++)
		{
			int temp = input[i] -'0';
			num *= 10;
			num += temp;
		}	

		int ans_m = 999999999 , ans_d = 999999999;
		for(int q=1 ; q<input.size() - 4 ; q++)
		{
			int n = pow(10,q);
			int cycle = num % n;
			int mol = num - (num - cycle)/n;
			int den=0;
			for(int i=0 ; i<q ; i++)
			{
				den *= 10;
				den += 9;
				
			}

			for(int i=0 ; i<input.size() - q-5 ; i++)
			{
				den *= 10;
			}

			int com = gcd(mol,den);
			mol /= com;
			den /= com;

			if(ans_d > den)
			{
				ans_d = den;
				ans_m = mol;
			}
		}

		printf("%d/%d\n",ans_m,ans_d );
	}

}



