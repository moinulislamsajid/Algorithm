#include<bits/stdc++.h>
using namespace std;


void  conquer(vector<int> &num,int st,int mid,int en)
{
    vector<int> mer;

    int indx1 = st;
    int indx2 = mid + 1;



   while(indx1<=mid && indx2<=en)
   {

       if(num[indx1]<=num[indx2])
       {
          mer.push_back(num[indx1++]);
       }
       else
       {
          mer.push_back(num[indx2++]);
       }
   }

   while(indx1<=mid)
   {
          mer.push_back(num[indx1++]);
   }

   while(indx2<=en)
   {
          mer.push_back(num[indx2++]);
   }

   for(int i=0,j=st;i<mer.size(); i++,j++)
   {
       num[j] = mer[i];
   }


}


void merge_sort(vector<int> &num,int st,int en)
{

    // if have only one element

     if(st>=en)
     {
         return;
     }

     // to find the mid value

      int mid = (st+en)/2;

      // for half part

      merge_sort(num,st,mid);
      merge_sort(num,mid+1,en);

      // called conquer function

      conquer(num,st,mid,en);


}

int main()
{
    int si;
    cout<<"Enter the size of arrays : ";
    cin>>si;

    vector<int> v(si);

    cout<<"Enter the arrays element : ";
    for(int i=0; i<si; i++)
    {
        cin>>v[i];
    }



    // called merge function

    merge_sort(v,0,si-1);


    cout<<"Sorted Arrays : ";
    for(int i=0; i<si; i++)
    {
        cout<<v[i]<<" ";
    }
}
