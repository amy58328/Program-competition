#include<bits/stdc++.h>
#define N 1000

using namespace std;
int n,cost;
int maxq ;
int cnt;

struct data
{
    int price;
    int qualit;
};

vector<data>comp[N+5];
map<string,int >id;

int ID(string s)
{
    if(!id.count(s))
        id[s] = cnt++;
    return id[s];
}

void init()
{
    maxq = -1;
    cnt = 0;
    id.clear();
    for(int i=0 ; i<N ; i++)
        comp[i].clear();
}

bool ok(int m)
{
    int sum = 0;
    for(int i=0 ; i<cnt ; i++)
    {
        int cheapest = cost+1;
        for(int j=0 ; j<comp[i].size() ; j++)
        {
            if(comp[i][j].qualit >= m)
                cheapest = min(cheapest,comp[i][j].price);
        }
        if(cheapest == cost+1)
            return false;
        sum += cheapest;
        if(sum > cost)
            return false;
    }

    return true;
}
int main()
{
    int T ;
    cin >> T ;
    while(T--)
    {
        init();

        cin >> n >> cost;
        for(int i=0 ; i<n ; i++)
        {
            char type[30],name[30];
            int p,q;
            scanf("%s%s%d%d",type,name,&p,&q);
            maxq = max(maxq,q);
            comp[ID(type)].push_back((data){p,q});
        }

        int l=0 ,r=maxq;
        while(l<r)
        {
            int m = l + (r-l+1)/2;

            // printf("%d %d %d\n",l,m,r);
            if(ok(m))
                l=m;
            else
                r=m-1;
        }

        cout << l << endl;
    }
}