#include<bits/stdc++.h>
#define N 10000

using namespace std;

int r[N+5];
int n;

bool ok(int m)
{
    int left[N+5],right[N+5];
    int x = r[1], y = m-r[1];
    left[1] = x;
    right[1] = 0;

    for(int i=2 ; i<=n ; i++)
    {
        // i is old
        if(i%2 == 1)
        {
            right[i] = min(y-right[i-1],r[i]);
            left[i] = r[i] - right[i];
        }

        // i is even
        else
        {   
            left[i] = min(x-left[i-1],r[i]);
            right[i] = r[i] - left[i];
        }
    }

    return left[n] == 0;

}

int main()
{
    
    while(cin >> n)
    {
        if(n == 0)
            break;
        
        for(int i=1 ; i<=n ; i++)
        {

            cin >> r[i];
        }


        // circle
        r[n+1] = r[1];
        int L=0,R=0;
        for(int i=1 ; i<=n ; i++)
        {
            L = max(L,r[i]+r[i+1]);

            //prepare for n is old
            R = max(R,r[i]*3);
        }


        // n is old
        if(n % 2 == 1)
        {
            while(L < R)
            {
                int m = L + (R-L)/2;

                if(ok(m))
                    R = m;
                else
                    L = m+1;
            }   
        }

        cout << L << endl;
    }
}