#include<bits/stdc++.h>
using namespace std;

void findRange(vector<int>&v,int &findx,int &sindx)
{
    int len = v.size();

    findx = -1;
    sindx = -1;
    int fmax = INT_MIN;
    int smax = INT_MIN;

    for(int i=0; i<len; i++)
    {
        if(v[i] > fmax)
        {
            smax = fmax;
            sindx = findx;
            fmax = v[i];
            findx = i;
        }
        else if(v[i] > smax && v[i] < fmax)
        {
            smax = v[i];
            sindx = i;
        }
    }

    if(findx > sindx)
    {
        swap(findx,sindx);
    }


}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>v(n);

        for(int i=0; i<n; i++)
        {
            cin>>v[i];
        }

        int findx,secdx;
        findRange(v,findx,secdx);

        cout<<findx<<" "<<secdx<<endl;
    }

}
