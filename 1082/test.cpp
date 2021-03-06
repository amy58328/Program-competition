#include<bits/stdc++.h>
using namespace std;
int cnt;
map<string,int>id;
int ID(string s){
    if(!id.count(s)) id[s] = cnt++;
    return id[s];
}
const int N = 1000+5;
struct Component{
    int price;
    int qualit;
};
int n,b;
vector<Component>comp[N];


bool ok(int q){
    int sum = 0;
    for(int i=0 ; i<cnt ; i++){
        int cheapest = b+1 , m = comp[i].size();
        for(int j=0 ; j<m ; j++)
        {
            if(comp[i][j].qualit >= q)
                cheapest = min(cheapest,comp[i][j].price);
        }    

        if(cheapest == b+1)
            return false;
        sum += cheapest;
        if(sum > b)
            return false;
    }
    return true;
   
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        // init
        scanf("%d %d",&n,&b);
        cnt = 0;
        for(int i=0 ; i<n ; i++)
            comp[i].clear();
        id.clear();

        // input
        int maxq = 0;
        for(int i=0 ; i<n ; i++)
        {
            char type[30],name[30];
            int p,q;
            scanf("%s%s%d%d",type,name,&p,&q);
            maxq = max(maxq,q);
            comp[ID(type)].push_back((Component){p,q});
        }

        //bineary search
        int l=0,r=maxq;
        while(l<r)
        {   

            int m =l+(r-l+1)/2;
            if(ok(m)) 
                l=m;
            else
                r = m-1 ;
        }

        cout << l << endl;
    }   
    return 0 ;
}