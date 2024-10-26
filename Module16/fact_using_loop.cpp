#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number you wanted to factorial value : ";
    cin>>n;

    int fact = 1;

    for(int i=1; i<=n; i++)
    {
        fact = fact * i;
    }

    cout<<fact<<endl;
}
