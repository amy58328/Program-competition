#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int num[n];
        for(int i = 0; i < n; i++)
            cin >>num[i];

        int target;
        cin >> target;

        sort(num,num+n);
        int ans1 , ans2;

        for(int i = 0; i < n-1; i++)
        {
            for(int j=i+1 ; j<n ; j++)
            {

                if(num[i] + num[j] == target)
                {
                    ans1 = num[i];
                    ans2 = num[j];
                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n",ans1,ans2);
    }
}