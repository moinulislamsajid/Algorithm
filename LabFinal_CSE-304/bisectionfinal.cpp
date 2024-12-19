#include<bits/stdc++.h>
using namespace std;

double cal(double x)
{
    return x*x*x - x - 1;
}

double e = 0.001;
double c;

void  bisection(double a,double b)
{
    if(cal(a)*cal(b)>=0)
    {
        cout<<"\nInvalid value of a and b";
        return;
    }

    int n=1;
    cout << setw(3) << "n"
         << setw(12) << "a"
         << setw(12) << "f(a)"
         << setw(12) << "b"
         << setw(12) << "f(b)"
         << setw(12) << "c"
         << setw(12) << "f(c)"
         << "   Update" << endl;


    while(true)
    {
        c = (a+b)/2;
        cout << setw(3) << n
         << setw(12) << a
         << setw(12) << cal(a)
         << setw(12) << b
         << setw(12) << cal(b)
         << setw(12) << c
         << setw(12) << cal(c);

         if(fabs(cal(c))<=e)
         {
             cout<<"  Root Found!"<<endl;
             break;
         }
         else if(cal(c) < 0)
         {
             cout<<"    a=c"<<endl;
             a=c;
         }
         else
         {
             cout<<"    b=c"<<endl;
             b=c;
         }

         n++;
    }

    cout<<"\nApproximate Root is : "<<fixed<<setprecision(5)<<c<<endl;
}

int main()
{
    double a,b;
    cout<<"\nEnter two number a and b : ";
    cin>>a>>b;

    if(a<b)
    {
        cout<<"The function we use is : x*x*x - x - 1"<<endl;
        cout<<"Initial a : "<<a<<"\t";
        cout<<"Initial b : "<<b<<endl<<endl;

        // called the function

        bisection(a,b);
    }
    else
    {
        cout<<"\nPlease Enter any two number a and b such that b is greater than a";

    }
}
