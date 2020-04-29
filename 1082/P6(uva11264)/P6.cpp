#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        long long arr[n];

        for(int i=0; i<n ; i++)
        {
            cin >> arr[i];
        }

        sort(arr,arr+n);

        int sum = 0;
        int ans = 0;

        for(int i=0 ; i<n ; i++)
        {
            sum += arr[i];
            // printf("sum = %d\n",sum);
            int index = i;
            while(arr[index] <= sum && index < n)
            {
                index++;
            }

            index -= 1;
            // printf("arr[%d] = %d, arr[%d] = %d\n",index,arr[index],index+1,arr[index+1]);
            if(index == i)
                ans += 1;
            else
                sum -= arr[i];
        }

        cout << ans << endl;
    }
}