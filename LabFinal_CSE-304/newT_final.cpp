#include<bits/stdc++.h>
using namespace std;

double cal(double x)
{
    return x*x*x - x -1;
}

double diff(double x)
{
    return 3*x*x - 1;
}
double e=0.001;


void falsePos(double x0)
{
    double x1;

    x1 = x0 - cal(x0) / diff(x0);

    int n=1;

    cout<<setw(3)<<"n"
        <<setw(12)<<"x0"
        <<setw(12)<<"f(x0)"
        <<setw(12)<<"f'(x0)"
        <<setw(12)<<"x1"
        <<setw(12)<<"f(x1)"
        <<"   Update"<<endl;


    while(true)
    {
        x1 = x0 - cal(x0) / diff(x0);
        cout<<setw(3)<<n
            <<setw(12)<<x0
            <<setw(12)<<cal(x0)
            <<setw(12)<<diff(x0)
            <<setw(12)<<x1
            <<setw(12)<<cal(x1)
            <<"   x0=x1"<<endl;


            if(fabs(cal(x1)) < e)
            {
                cout<<"\nApproximate Root is : "<<fixed<<setprecision(5)<<x1<<endl;
                return;
            }

            x0 = x1;
            n++;

    }




}


    int main()
    {
        double a,b;
        cout<<"\nEnter two number a and b : ";
        cin>>a>>b;

        if(a>=b || cal(a)*cal(b)>=0)
        {
            cout<<"\nInvalid a and b please press again";

        }
        else
        {
            cout<<"The function use is : x*x*x - x - 1"<<endl;
            cout<<"Initial a : "<<a<<"\t";
            cout<<"Initial b : "<<b<<endl<<endl;;

            double x0 = (a+b)/2;

            // called the function

            falsePos(x0);
        }

    }
