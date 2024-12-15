#include<bits/stdc++.h>
using namespace std;

void conquer(int num[],int x,int mid,int y)
{
    int mer[y-x+1];
    int indx1 = x;
    int indx2 = mid+1;
    int merIndx = 0;

    while(indx1<=mid&&indx2<=y)
    {
        if(num[indx1]>num[indx2])
        {
            mer[merIndx++] = num[indx1++];
            // mer[indx]
            // indx++;
        }
        else
        {
            mer[merIndx++] = num[indx2++];
        }
    }


    while(indx1<=mid)
    {
        mer[merIndx++] = num[indx1++];

    }
    while(indx2<=y)
    {
        mer[merIndx++] = num[indx2++];
    }

    // now holed the arrays

    for(int i=0,j=x; i<y-x+1; i++,j++)
    {
        num[j] = mer[i];
    }
}

void mergeFun(int num[],int x,int y)
{
    // if have only one element than is always sorted

    if(x>=y)
    {
        return;
    }

    // to find the mid value

    int mid = (x+y)/2;

    // for half part
    // called recursive function

    mergeFun(num,x,mid);

    // for second part

    mergeFun(num,mid+1,y);

    // called conquer fun

    conquer(num,x,mid,y);
}
int main()
{
     int n;
     cout<<"Enter the size of arrays : ";
     cin>>n;

     int num[n];

     cout<<"Enter the arrays element : ";
     for(int i=0; i<n; i++)
     {
         cin>>num[i];
     }

     // called the merge function

     mergeFun(num,0,n-1);

     // sorted arrays

     cout<<"Sorted Arrays : ";
     for(int i=0; i<n; i++)
     {
         cout<<num[i]<<" ";
     }
}
