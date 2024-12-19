#include<bits/stdc++.h>
using namespace std;

double cal(double x)
{
    return x*x*x - x - 1;
}

double e=0.001;
double c;

void falsePosition(double a,double b)
{
    if(cal(a)*cal(b)>=0)
    {
        cout<<"\nIncorrect value of a and b "<<endl;
        return;
    }

    cout<<setw(3)<<"n"
        <<setw(12)<<"a"
        <<setw(12)<<"f(a)"
        <<setw(12)<<"b"
        <<setw(12)<<"f(b)"
        <<setw(12)<<"c"
        <<setw(12)<<"f(c)"
        <<"   Update"<<endl;

    int n=1;
    c = a - cal(a) * (b-a) / (cal(b) - cal(a));

    while(true)
    {
        c = a - cal(a) * (b-a) / (cal(b) - cal(a));
        cout<<setw(3)<<n
        <<setw(12)<<a
        <<setw(12)<<cal(a)
        <<setw(12)<<b
        <<setw(12)<<cal(b)
        <<setw(12)<<c
        <<setw(12)<<cal(c)
        <<"    a=c"<<endl;

        if(fabs(cal(c))<e)
        {
            cout<<"\nApproximate root is : "<<fixed<<setprecision(5)<<c<<endl;
            return;
        }

        a=c;
        n++;

    }
}

int main()
{
    double a,b;
    cout<<"\nEnter a and b : ";
    cin>>a>>b;

    if(a<b)
    {
        cout<<"The function we use is : x*x*x - x - 1"<<endl;
        cout<<"Initial a : "<<a<<"\t";
        cout<<"Initial b : "<<b<<endl<<endl;

        // called the function

        falsePosition(a,b);

    }
    else
    {
        cout<<"\nPlease enter a and b such that b is greater than a"<<endl;
    }
}

