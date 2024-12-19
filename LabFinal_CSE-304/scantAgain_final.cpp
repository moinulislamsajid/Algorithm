#include<bits/stdc++.h>
using namespace std;

double cal(double x)
{
    return x*x*x - x -1;
}

double e=0.001;
double c;
void scantMethod(double a,double b)
{

    int n=1;
    cout<<setw(3)<<"n"
        <<setw(12)<<"a"
        <<setw(12)<<"f(a)"
        <<setw(12)<<"b"
        <<setw(12)<<"f(b)"
        <<setw(12)<<"c"
        <<setw(12)<<"f(c)"
        <<"  Update"<<endl;

    c = a - cal(a) * (b-a) / ((cal(b)) - cal(a));

    while(true)
    {
        c = a - cal(a) * (b-a) / ((cal(b)) - cal(a));

        cout<<setw(3)<<n
        <<setw(12)<<a
        <<setw(12)<<cal(a)
        <<setw(12)<<b
        <<setw(12)<<cal(b)
        <<setw(12)<<c
        <<setw(12)<<cal(c)
        <<"   a=b, b=c"<<endl;

        if(fabs(cal(c))<e)
        {
            cout<<"\nApproximate Root is : "<<fixed<<setprecision(6)<<c<<endl;
            return;
        }

        a=b;
        b=c;
        n++;
    }
}

int main()
{

    double a,b;
    cout<<"\nEnter two number : ";
    cin>>a>>b;

    if(a>=b || cal(a)*cal(b)>=0)
    {
        cout<<"\nInvalid a and b "<<endl;
    }
    else
    {
        cout<<"The function use is : x*x*x - x -1"<<endl;
        cout<<"Initial a : "<<a<<"\t";
        cout<<"Initial b : "<<b<<endl<<endl;

        // called the function

        scantMethod(a,b);
    }
}
