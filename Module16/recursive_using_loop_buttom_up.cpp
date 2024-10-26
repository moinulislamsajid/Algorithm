#include<bits/stdc++.h>
using namespace std;

int main()
{

    int si;
    cout<<"Enter the size of arrays : ";
    cin>>si;

    int num[si];

    num[0] = 0;
    num[1] = 1;

    for(int i=2; i<=si; i++)
    {
        num[i] = num[i - 1] + num[i-2];
    }

    cout<<num[si]<<endl;
}
