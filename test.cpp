#include<bits/stdc++.h>
#define N 100

using namespace std;
struct node {
    char status;
    int place;
};

int n,r,l;
node rock[N+5];

void readdata()
{
    rock[0].status = 'B';
    rock[0].place = 0;
    for(int i=1 ; i<n+1 ; i++)
    {
        cin >> rock[i].status ;
        getchar();
        cin >> rock[i].place;
    }
    rock[n+1].status = 'B';
    rock[n+1].place = r;
}

bool ok(int m)
{
    printf("======ok======\n");
    int front = 0;
    //go 
    for(int i=1 ; i<n+2 ; i++)
    {
        printf("%d %d %d\n",i,rock[i].place , rock[front].place);
            
        printf("%d\n",abs(rock[i].place - rock[front].place));
        if(abs(rock[i].place - rock[front].place) > m)
        {
           
            return false;
        }
        int p = i;
        while(true)
        {
           p++;

           

           if(abs(rock[p].place - rock[front].place) > m )
           {
               front=p-1;
               i=p;
               if(rock[p].status == 'B')
               {
                    break;
               }
               if(rock[front].status == 'S')
                    rock[front].status = 'X';
               break;
           }


        }
        
    }
    return true;
}


void print_test()
{
    for(int i=0 ; i < n+2 ; i++)
    {
        printf("%c-%d ",rock[i].status,rock[i].place);
    }
    cout << endl;
}
int main()
{
    int T;
    cin >> T;
    for(int I=1; I<=T ;I++)
    {
        cin >> n >> r;
        readdata();
        l=0;
        print_test();
        while(l<r)
        {
            int m = (l+r)/2;
            printf("[%d %d %d]",l,m,r); 
            if(ok(m))
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        printf("ans = %d",l);

        // for(int i=0 ; i<n+2; i++)
        // {
        //    printf("%d : %d - %c",i,rock[i].place,rock[i].status);
        // }

    }
}