#include<bits/stdc++.h>

using namespace std;

int A ;
int B ;
int C ;
int D ;

void init()
{
	A = 0;
	B = 0;
	C = 0;
	D = 0;
}

int main()
{
	int t ;
	cin >>t ;

	for(int q=1 ; q<=t ; q++)
	{
		init();
		string S,T;

		cin >> S >> T;

		for(int i=0 ; i<S.size() ; i++)
		{
			if(S[i] == '0' && T[i] == '1')
			{
				B++;
			}

			else if(S[i] == '1' && T[i] == '0')
			{
				A++;
			}

			else if (S[i] == '?' && T[i] == '1')
			{
				C++;
			}

			else if(S[i] == '?' && T[i] == '0')
			{
				D++;
			}
		}

		if(A <= B)
		{
			int temp = B  + C + D;
			cout <<"Case "<< q << ":" << " " <<  temp << endl;
		}

		else if(A > B)
		{
			int temp = A -B;

			if(temp <= C)
			{
				temp = temp + B + C + D;
				cout <<"Case "<< q << ":" << " " <<  temp << endl;
			}

			else 
			{
				cout <<"Case "<< q << ":" << " " <<  "-1" << endl;
			} 


		}


	}
	return 0 ;
}