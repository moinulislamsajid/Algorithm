#include<bits/stdc++.h>
using namespace std;


void conquer(int num[],int st,int mid,int en)
{

    int me[en - st + 1];

    int indx1 = st;
    int indx2 = mid+1;
    int mIndx =0;

    while(indx1<=mid && indx2<=en)
    {
        if(num[indx1]<=num[indx2])
        {
            me[mIndx++] = num[indx1++];
        }
        else
        {
            me[mIndx++] = num[indx2++];
        }
    }

    while(indx1<=mid)
    {
        me[mIndx++] = num[indx1++];

    }

    while(indx2<=en)
    {
        me[mIndx++] = num[indx2++];

    }

    for(int i=0,j=st; i<en - st + 1; i++,j++)
    {
        num[j] = me[i];
    }

}




void merge_sort(int num[],int st,int en)
{

    // if have only one element

    if(st>=en)
    {
        return;
    }

    int mid = (st+en)/2;
    merge_sort(num,st,mid);
    merge_sort(num,mid+1,en);

    // called the conquer function

    conquer(num,st,mid,en);

}


int main()
{
    int n;
    cout<<"Enter the size of the arrays : ";
    cin>>n;

    int num[n];

    for(int i=0; i<n; i++)
    {
        cin>>num[i];
    }

    // called the conquer function

    merge_sort(num,0,n-1);

    cout<<"Sorted Arrays : "<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<num[i]<<" ";
    }

}
