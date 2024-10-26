#include<bits/stdc++.h>
using namespace std;

class pairClass
{
public:

    int num,num1;
};

int main()
{

   pairClass pc;
   pc.num = 10;
   pc.num1 = 20;

   cout<<pc.num<<" "<<pc.num1<<" ";

   pair<int,int> p;
   p = make_pair(98,76);

   cout<<p.first<<" "<<p.second<<" ";


}
