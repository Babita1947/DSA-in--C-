#include<iostream>
#include<map>
#include<string>
#include<utility>
using namespace std;
int main()
{
    //object
    map<int,string>m1={{1,"Bhopal"},
                       {2,"Indore"},
                       {3,"Jabalpur"},
                       {4,"Ujjain"},
                       {5,"Gwalior"}
                       };
    //Access
    //1. Implicit iterator
    for(auto x:m1)
    {
        cout<<x.first<<" "<<x.second<<" "<<endl;
    }
    cout<<endl;
    map<int,string>::iterator it;
    for(it=m1.begin();it!=m1.end();it++)
       cout<<it->first<<" "<<it->second<<endl;
    cout<<endl;
    cout<<"3rd position = "<<m1.at(3)<<endl<<endl;
    cout<<"How many times 5 is present = "<<m1.count(5)<<endl<<endl;
    
    pair<int,string> p1={6,"Asansol"};
    m1.emplace(p1);
    for(auto e:m1)
    {
        cout<<e.first<<" "<<e.second<<endl;
    }
    cout<<endl;
    m1.erase(m1.begin());
    for(auto e:m1)
    {
        cout<<e.first<<" "<<e.second<<endl;
    }
    cout<<endl;
    
    return 0;
}