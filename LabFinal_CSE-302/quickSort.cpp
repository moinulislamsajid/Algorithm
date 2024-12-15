#include<bits/stdc++.h>
using namespace std;

int partion(int num[],int st,int en)
{
    int pivot = num[en];
    int i = st-1;

    for(int j=st; j<en; j++)
    {
        if(num[j]<pivot)
        {
            i++;

            // time to need swap

            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }

    // increase the index

    i++;

    // need again the code swap

    int temp = num[i];
    num[i] = pivot;
    num[en] = temp;

    // return the pivot index

    return i;
}

void quickSort(int num[],int st, int en)
{

    if(st<en)
    {
        int partindx = partion(num,st,en);
        quickSort(num,st,partindx-1);
        quickSort(num,partindx+1,en);
    }

}

int main()
{
    int n;
    cout<<"Enter the size of arrays : ";
    cin>>n;

    int num[n];

    cout<<"Enter element of arrays : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>num[i];
    }

    // called the method

    quickSort(num,0,n-1);

    cout<<"Sorted Arrays : ";
    for(int i=0; i<n; i++)
    {
        cout<<num[i]<<" ";
    }
}
