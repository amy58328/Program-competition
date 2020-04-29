#include<bits/stdc++.h>

using namespace std;

struct node 
{
    double xr,xl;
};

bool rule(node a , node b)
{
    return a.xr < b.xr ;
}

int main()
{
    int n,length;
    int index = 0;
    while(cin >> n >> length)
    {
        if(n == 0 && length == 0)
            break;

        // cout << n << " " << length << endl;
        node land[n];

        int flag = 0;
        for(int i=0 ; i<n ; i++)
        {
            int x,y;
            cin >> x >>y ;
            
            if(y > length)
            {
                flag = 1;
            }
            land[i].xr = x + sqrt(length*length - y*y);
            land[i].xl = x - sqrt(length*length - y*y);

        }

        if(flag)
        {
            printf("Case %d: -1\n",++index);
            continue;
        }


        sort(land,land+n,rule);

        int ans = 1;
        int place = land[0].xr;
        for(int i=1 ; i<n ; i++)
        {
            // not in the middler
            if(place < land[i].xl)
            {
                ans ++ ;
                place = land[i].xr;
            }
        }

        printf("Case %d: %d\n",++index,ans);


    }
}