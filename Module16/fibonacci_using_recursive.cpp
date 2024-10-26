#include<bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }

    return fibo(n-1) + fibo(n-2);


}

int main()
{
    int  n;
    cout<<"Enter the number you want to Fibonacci series : ";
    cin>>n;

    int i = 0;

    while(i<n)
    {
        cout<<fibo(i)<<" ";
        i++;
    }
}
