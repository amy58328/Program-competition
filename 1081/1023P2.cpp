#include<bits/stdc++.h>

using namespace std;

long long length[50000];
long long Sum[50000];
string last_string("0");


void init()
{	
	Sum[0] = 0;
	for(long long i=1 ; i<50000 ; i++)
	{
		stringstream ss;
		ss << i;
		string temp = ss.str();
		last_string.append(temp,0,temp.size());	
		long long  len = last_string.length();
		length[i] = len-1;
		Sum[i] = Sum[i-1] + length[i];		
	}
}


long long findplace(long long a,long long l , long long r)
{
	int mid = (l+r)/2;

	if(Sum[mid] < a && mid != l )
	{
		mid = findplace(a,mid,r);
	}
	else if(Sum[mid] > a &&mid != l)
	{
		mid = findplace(a,l,mid);
	}

	if( mid == l)
		return mid ; 
}
int main()
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	init(); 
	int t;
	cin>>t;
	while(t--)
	{
		long long input;
		cin >> input;
		
		long long arr_number = findplace(input,1,50000);
		input -= Sum[arr_number];
		printf("%c\n",last_string[input]);
	}
	return 0;
}	

// 想法:
// 先把
// 每一個的長度先找出來 (開到五萬)
// 再用binary search 去找出input 在哪一個陣列李
// 最後再找出最後一個陣列裡所有的數字 用string 的型態存取 stringstream 