#include<bits/stdc++.h>
#define N 900000

using namespace std;

int dp[N+5];
int n[35];
int sum ;

bool check(int num )
{
    for(int i=0 ; i<num-1 ; i++)
    {
        if(n[i] > n[i+1])
            return true;
    }

    return false;
}

bool same(int num)
{
    dp[0] = 1;
    for(int i=0 ; i<num ; i++)
    {
        if(dp[n[i]] == 1)
            return true;

        for(int j=sum ; j>=n[i] ; j--)
        {
            int temp = j - n[i];
            if(dp[temp])
            {
                dp[j] = 1;
            }
        }
    }

    return false;
}

void init()
{
    memset(dp, 0, sizeof(dp));
    sum = 0;   
}

int main()
{
    int num;
    int t=1 ;
    while (cin >> num)
    {
        init();
        int flag = 1;
        for(int i=0 ; i<num ; i++)
        {
            cin >> n[i];
            sum += n[i];
        }

        if(check(num))
        {
            flag = 0;
        }
        
        if(same(num) && flag )
        {
            flag = 0;
        }

        printf("Case #%d:",t++);

        for(int i=0;i<num ; i++)
        {
            cout << " "<<n[i] ;
        }
        cout << endl;

        if(flag == 0)
        {
            cout << "This is not an A-sequence." << endl;
        }
        else
        {
            cout <<"This is an A-sequence." << endl;
        }
    }
}
