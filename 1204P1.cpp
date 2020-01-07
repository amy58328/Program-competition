#include<bits/stdc++.h>

using namespace std;
string input;
int ans,num;
int mol ,den;
int deg ;


void getint()
{   
    num = 0;

    for(int i=2 ; i<input.size() - 3 ; i++)
    {
        int temp = input[i] - '0';
        num *= 10;
        num += temp;
        deg ++;
    }
}

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }

    else
        return gcd(b,a%b);
}

void getmol()
{
    int ten = 0;
    while(ten != deg)
    {   
        ten += 1;

        int temp1 = num % (int)pow(10,ten);
        temp1 = num - temp1;
        temp1 /= (int)pow(10,ten);
        temp1 = num - temp1;

        int temp2 = 0 ;
        for(int i=0 ; i<ten ; i++)
        {
            temp2 *= 10;
            temp2 += 9;
        }
        for(int i=0 ; i<deg - ten ; i++)
        {
            temp2 *= 10;
        }

        int gg = gcd(temp1,temp2);
        if(temp2 / gg < den )
        {
            den = temp2 / gg;
            mol = temp1/ gg;
        }

    }
}



void init()
{
    num = 0;
    deg = 0;
    den = 999999999;
}
int main()
{
    while(getline(cin,input))
    {
        if(input.size() == 1)
            break;
        init();
        getint();
        getmol();


        printf("%d/%d\n",mol,den);
        
    }
}
